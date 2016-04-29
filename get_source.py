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

