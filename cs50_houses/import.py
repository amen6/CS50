import cs50
import csv
from sys import argv , exit

if len(argv) != 2:
    print('error occured')
    exit(1);

db = cs50.SQL("sqlite:///students.db")

with open(argv[1], "r") as characters:

    reader = csv.DictReader(characters)

    for row in reader:

        temp = row['name'].split()
        first , middle , last = temp[0], temp[1] if len(temp) == 3 else None , temp[-1]

        house = row['house']
        birth = row['birth']

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",first, middle, last, house, birth)
