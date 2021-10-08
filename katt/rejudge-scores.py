# \copy (select submission_id, problem_testcase_group_id, extract (epoch from time) as time, judgement_group_run.score, username, extract (epoch from flexible_starttime) as starttime from judgement_group_run  join current_judgement using (judgement_id)  join submission using (submission_id)  join author using (author_id)  join team_member using (author_id)  join team using (team_id)  join problem using (problem_id) join session using (session_id) where problem_name = 'pokatt20.tagresan' and judgement_group_run.status_id = 16 and short_name = 'pokatt20') To '/tmp/result.csv' With CSV;
from collections import defaultdict

authors = set()
submissions = {}

f = open('result.csv')
for line in f:
    line = line.strip()
    if not line:
        continue
    parts = line.split(',')
    assert len(parts) == 6
    submission_id = int(parts[0])
    subgroup = int(parts[1])
    time = float(parts[2])
    score = float(parts[3])
    author = parts[4]
    authors.add(author)
    start_time = float(parts[5])
    early = (time < start_time + 24*60*60)
    if submission_id not in submissions:
        submissions[submission_id] = (time, author, early, [])
    submissions[submission_id][3].append((subgroup, score))

best_scores = {}
best_subid = {}

for submission_id, (time, author, early, groups) in submissions.items():
    if early:
        for gr, score in groups:
            if gr not in best_scores or score > best_scores[gr]:
                best_scores[gr] = score
                best_subid[gr] = submission_id

group_base = 13370
print("Max score per group:")
for g in range(10):
    print(f"{g+1:<3} {best_scores[group_base + g]:<6} (sub-ID {best_subid[group_base + g]}, {submissions[best_subid[group_base + g]][1]})")
print()

early_best = defaultdict(lambda: (0.0, -1))
late_best = defaultdict(lambda: (0.0, -1))

for submission_id, (time, author, early, groups) in submissions.items():
    total = 0
    for gr, score in groups:
        if group_base <= gr < group_base + 10:
            score = score / best_scores[gr] * 10
            total += score
    if early:
        early_best[author] = max(early_best[author], (total, submission_id))
    else:
        late_best[author] = max(late_best[author], (total, submission_id))

for author in sorted(authors):
    early = early_best[author]
    late = late_best[author]
    late = max(late, early)
    ups = f", upsolved to {late[0]} ({late[1]})" if late[0] != early[0] else ""
    print(f"{author.ljust(25)} {early[0]} ({early[1]}){ups}")
