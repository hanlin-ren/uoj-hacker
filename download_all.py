from get_source import *
from get_submissions import *
from shutil import *
from commands import *
import os

'''
pid = 75
tot = GetList(pid)
'''

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

def DownloadAllSources(pid) :
	if os.path.isdir(str(pid)) == 0:
		os.mkdir(str(pid))
	os.chdir(str(pid))
	global tot
	tot = GetList(pid)
	flist = open("list.txt", "w")
	for src in tot :
		fout = open(src[0] + ".cpp", "w")
		fout.write(GetSourceCode(int(src[0])))
		fout.close()
		flist.write(src[0] + " " + src[1] + "\n")
		Compile(src)
	flist.close()

def CompileGenerator(pid) :
	gen = '../gen/' + str(pid) + '.cpp'
	dst = 'gen.cpp'
	print gen
	if os.path.isfile(gen) == 0 :
		print "No Generator !"
		return 1
	print "Compiling generator ..."
	copyfile(gen, dst)
	cmd = "g++ -o gen gen.cpp"
	os.system(cmd)

def RunOnce() :
	hacked = 0
	os.system("./gen > in")
	for src in tot :
		print "Running " + src[0]
		os.system("./" + src[0] + " < in > " + src[0] + ".out")
	base = tot[0][0]
	for src in tot :
		(status, output) = getstatusoutput("diff -w " + base + ".out " + src[0] + ".out")
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
	os.chdir(str(pid))
	CompileGenerator(pid)
	ReadTot()
	a = 0
	while a == 0 :
		a = RunOnce()

pid = 127
#DownloadAllSources(pid)
Pai(pid)


