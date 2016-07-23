from urllib2 import *
from sgmllib import SGMLParser
import HTMLParser

class Spider_For_Source_Code(SGMLParser) :
  in_code = 0
  source_code = ""
  def start_code(self, attrs) :
    self.in_code = 1
  def end_code(self) :
    self.in_code = 0
  def handle_data(self, text) :
    if (self.in_code) :
      self.source_code = self.source_code + HTMLParser.HTMLParser().unescape(text)

sfsc = Spider_For_Source_Code()
def GetSourceCode(s_no) :
  print "Fetching sid = " + str(s_no)
  content = urlopen("http://uoj.ac/submission/" + str(s_no)).read()
  sfsc.source_code = ""
  sfsc.feed(content)
  return sfsc.source_code

tot_submissions = []
last_submissions = []
language = []
class Spider_For_Submission_List(SGMLParser) :
  in_thead = 0
  cnt_item = 0
  in_a = 0
  submissions = []
  cur_no = 0
  def start_thead(self, attrs) :
    self.in_thead = 1
  def end_thead(self) :
    self.in_thead = 0
  def start_tr(self, attrs) :
    self.cnt_item = 0
  def start_td(self, attrs) :
    self.cnt_item = self.cnt_item + 1
  def start_a(self, attrs) :
    self.in_a = 1
    if self.in_thead == 0 :
      if self.cnt_item == 1 :
        href = [v for k, v in attrs if k == 'href']
        if href :
          _href = href[0]
          submission_no = _href[len('/submission/'):]
          self.cur_no = submission_no
  def end_a(self) :
    self.in_a = 0
  def handle_data(self, text) : 
    if self.in_thead == 0 :
      if self.cnt_item == 7 :
        self.submissions.append([self.cur_no, text])

sfsl = Spider_For_Submission_List()
def GetList_(prob, page) :
  global last_submissions, tot_submissions
  print "Fetching Problem " + str(prob) + ", Page " + str(page)
  content = urlopen("http://uoj.ac/submissions?problem_id=" + str(prob) + "&min_score=100&page=" + str(page)).read()
  sfsl.submissions = []
  sfsl.feed(content)
  if last_submissions == sfsl.submissions :
    return 0
  else :
    tot_submissions.extend(sfsl.submissions)
    last_submissions = sfsl.submissions
    return 1

def GetList(prob) :
  i = 1
  old_content = "2333"
  content = ""
  while GetList_(prob, i) :
    i = i + 1
  return tot_submissions

from shutil import *
from commands import *
import os
tot = []
def Compile(src) :
  fn = src[0]
  lang = src[1]
  cmd = ""
  if lang == "C++" :
    cmd = "g++ " + fn + ".cpp -o " + fn + " -lm -O2 -DONLINE_JUDGE"
  elif lang == "C++11" :
    cmd = "g++ " + fn + ".cpp -o " + fn + " -lm -O2 -DONLINE_JUDGE -std=c++11"
  elif lang == "C" :
    cmd = "gcc " + fn + ".cpp -o " + fn + " -lm -O2 -DONLINE_JUDGE"
  elif lang == "Pascal" :
    cmd = "fpc " + fn + ".cpp -O2"
  else : return 1
  os.system(cmd)

chk=0
valdict=set()
def valid(str):
  global valdict
  if not chk:
    return 1
  else:
    return str in valdict

def DownloadAllSources(pid) :
  if os.path.isdir(str(pid)) == 0:
    os.mkdir(str(pid))
  os.chdir(str(pid))
  global tot
  tot = GetList(pid)
  flist = open("list.txt", "w")
  for src in tot :
    if src!=tot[0] and not valid(src[0]):
      continue
    fout = open(src[0] + ".cpp", "w")
    fout.write(GetSourceCode(int(src[0])))
    fout.close()
    flist.write(src[0] + " " + src[1] + "\n")
    Compile(src)
  flist.close()

hasspj=0
ext=''
sep="/"

def CompileGenerator(pid) :
  gen = '..'+sep+'gen'+sep + str(pid) + '.cpp'
  dst = 'gen.cpp'
  print gen
  if os.path.isfile(gen) == 0 :
    print "No Generator !"
    return 1
  print "Compiling generator ..."
  copyfile(gen, dst)
  cmd = "g++ -o gen"+ext+" gen.cpp"
  os.system(cmd)
  spjp='..'+sep+'spj'+sep+ str(pid) + ext
  print spjp
  print os.path.isfile(spjp)
  global hasspj
  if os.path.isfile(spjp) ==1:
    copyfile(spjp,'spj'+ext)
    hasspj=1
  else:
    hasspj=0

def RunOnce() :
  global hasspj
  hacked = 0
  print "Gening..."
  os.system('.'+sep+"gen > in")
  for src in tot :
    print "Running " + src[0]
    os.system('.'+sep+src[0] + " < in > " + src[0] + ".out")
  base = tot[0][0]
  for src in tot :
    #note that getstatusoutput cannot work properly on Windows
    if hasspj==0:
      status=os.system("diff -w " + base + ".out " + src[0] + ".out")
    else:
      status=os.system('.'+sep+"spj in " + src[0] + ".out " + base + ".out")
    if status != 0 :
      hacked = 1
      print src[0]
  return hacked

def ReadTot() :
  f = open("list.txt")
  global tot
  tot = []
  content = f.readlines()
  for line in content :
    a = line.split(' ')
    a[1] = a[1][:-1] # Fuck off '\n'
    tot.append(a)

def Pai(pid) :
  CompileGenerator(pid)
  ReadTot()
  a = 0
  while a == 0 :
    a = RunOnce()

print "Problem no.:",
pid = int(raw_input())
print "Input def. no :",
s=raw_input().split()
if len(s):
  chk=1
  for i in s:
    valdict.add(i)
DownloadAllSources(pid)
Pai(pid)
