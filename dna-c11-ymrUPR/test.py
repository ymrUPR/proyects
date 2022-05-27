import os

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

expected = {1: 'Bob', 2: 'Match', 3:'Match', 4:'Alice', 5: 'Lavender', 6: 'Luna', 7:'Ron', 8:'Ginny', 9:'Draco', 10:'Albus', 11:'Hermione', 12:'Lily', 13:'Match', 14:'Severus', 15:'Sirius', 16:'Match', 17:'Harry', 18:'Match', 19:'Fred', 20:'Match'}

ctr = 0
total = 0
for k in sorted(expected.keys()):
  if int(k) >= 5:
    stream = os.popen("./main databases/large.csv sequences/" + str(k) + ".txt")
  else:
    stream = os.popen("./main databases/small.csv sequences/" + str(k) + ".txt")
  output = stream.read()
  print("\n=================================")
  print(k, output)
  if expected[k].lower() in output.lower():
    print("Test %s correct!" % (k))
    ctr = ctr + 1
  else:
    print(bcolors.WARNING + "Test %s incorrect! Expected %s <=============="  % (k, expected[k]))
    print(bcolors.ENDC)
  total = total + 1
  print("=================================")


print (bcolors.OKGREEN + "Results: %s out of %s" % (ctr,total))