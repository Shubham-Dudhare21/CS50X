import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if 3 < len(argv) or len(argv) < 3:
        return 1

    # setting the variables for filname arguments
    database_filename = argv[1]
    sequence_filename = argv[2]

    # TODO: Read database file into a variable
    datafile = open(database_filename, 'r')
    buffer = csv.DictReader(datafile)

    # getting the total str types in the dna for the csv file excluding name index
    STR_heads = []
    index = 0
    for c in buffer.fieldnames:
        if index > 0:
            STR_heads.append(c)
        index += 1

    # TODO: Read DNA sequence file into a variable
    dnafile = open(sequence_filename, 'r')
    sequence = dnafile.read()

    # TODO: Find longest match of each Str in DNA sequence
    matches = {}
    for Str in STR_heads:
        number = longest_match(sequence, Str)
        matches[Str] = str(number)
    str_count = len(matches)

    # TODO: Check database for matching profiles
    match_count = 0
    for row in buffer:
        for Str in matches:
            if row[Str] == matches[Str]:
                match_count += 1
        if match_count == str_count:
            print(row['name'])
            break
        else:
            match_count = 0
    if match_count == 0:
        print("No match")

    dnafile.close()
    datafile.close()
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


main()
