import sys

total_score = 0
verdicts = []
for line in sys.stdin.readlines():
    verdict, score = line.split()
    total_score += float(score)
    if verdict != 'AC':
        verdicts.append(verdict)
verdicts.append('AC')
total_score = min(total_score, 100)
print "%s %f" % (verdicts[0], total_score)
