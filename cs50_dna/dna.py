from sys import argv
import csv


def get_max(txt_read, sub):
    ans = [0] * len(txt_read)
    for i in range(len(txt_read)-len(sub), -1, -1):
        if txt_read[i: i +len(sub)] == sub:
            if i + len(sub) > len(txt_read):
                ans[i]=1
            else:
                ans[i] = ans[i +len(sub)] + 1
    return max(ans)

def print_match(csv_read, actual):
    for line in csv_read:
        person = line[0]
        value = [int(val) for val in line[1:]]
        if value == actual:
            print(person)
            return
    print('no match founded')

def main():
    if argv != 3:
        print('problem occured-not enough data-')
        return 1
    csv_path = argv[1]
    with open(csv_path) as csv_file:
        csv_read = csv.reader(csv_file)
        all_seq = next(csv_read)[1:]

        txt_path = argv[2]
        with open(txt_path) as txt_file:
            txt_read = txt_file.read()
            actual = [get_max(txt_read, seq) for seq in all_seq]

        print_match(csv_read, actual)

if __name__ == "__main__":
        main()