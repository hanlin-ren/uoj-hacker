from urllib2 import *
from sgmllib import SGMLParser
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

