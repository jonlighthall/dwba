#Attempt to clean up the ptolemy output files

import string
import sys

def isfloat(str):
	ret=1
	try:
		this=float(str)
	except ValueError:
		ret=0
	return ret

infile = open(sys.argv[1])				#open file given as command line argument
outfile = open(sys.argv[1]+'-clean','w')		#open file for writing clean version to

while True:
	
	line=infile.readline()
	
	if (line==''):					#EOF reached so break
		break
	
	words=string.split(line)			#split the input line into its component parts
	
	if (len(words)>1 and words[0]=='ANGLE'):	#look for lines starting with 'ANGLE'
		
		while True:
		
			temp=string.split(infile.readline())
			
			if (len(temp)>1 and temp[0]=='0TOTAL:'):
				#outfile.write('\n\n')	#insert two new lines for gnuplots index function
				break
			
			elif (len(temp)>8 and isfloat(temp[0]) and isfloat(temp[1])):
				outfile.write(temp[0] + ' ' + temp[1] + '\n')
			
			


infile.close()						#close files nicely
outfile.close()
