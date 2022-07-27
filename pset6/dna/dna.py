import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("need a csv file and a txt file")
        sys.exit(1)


    # TODO: Read database file into a variable
    csvfile = open(sys.argv[1], "r")
    csvfile_dictreader = csv.DictReader(csvfile)
    subsequences = csvfile_dictreader.fieldnames[1:]


    # TODO: Read DNA sequence file into a variable
    txtfile = open(sys.argv[2], "r")
    txtfile_reader = csv.reader(txtfile)
    dna_sequence = list(next(txtfile_reader))[0]


    # TODO: Find longest match of each STR in DNA sequence
    longest_runs = []
    for i in range(len(subsequences)):
        longest_run = longest_match(dna_sequence, subsequences[i])
        longest_runs.append(longest_run)


    # TODO: Check database for matching profiles
    matched_name = ""
    for row in csvfile_dictreader:
        match = 0
        #identify the name in that row dictionary
        name = str(row["name"])
        #if there are x dna patterns, find the number of times they repeat for each person
        for i in range(len(subsequences)):
            #this checks for "AGATC" for example
            subsequence_name = subsequences[i]
            datasetnum = row[subsequence_name]

            #if there are 3 matches then we print the name in the row.
            if int(longest_runs[i]) == int(datasetnum):
                match += 1
                if match == len(subsequences):
                    matched_name = name
                    break

            else:
                continue

    if len(matched_name) > 0:
        print(str(matched_name))
    else:
        print("No match")



    txtfile.close()
    csvfile.close()
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
