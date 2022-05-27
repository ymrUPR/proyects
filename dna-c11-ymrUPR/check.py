import check50

expected = [["databases/small.csv", "sequences/1.txt", "sequences/1.txt"],
["databases/small.csv", "sequences/2.txt", "maria"]]

check50.exists("main.cpp")
check50.exists("sequences")
check50.exists("databases")
for test in expected:
  try:
    check50.run("./main " + test[0] + " " + test[1]).stdout("^" + test[2], test[2] + "\n", timeout=5).exit()
  except:
    print("No paso la prueba: " + test[0] + " " + test[1] + ":")
    print("Expected:\n" + test[2])
    print("Got:" + check50.run("./main " + test[0] + " " + test[1]).stdout())


