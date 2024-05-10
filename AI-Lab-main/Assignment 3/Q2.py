def process_data(input_filename, output_filename):
    with open(input_filename) as r, open(output_filename, 'w') as w:
        numbers = map(int, r.readline().split())
        for number in numbers:
            w.write(str(number ** 2) + " ")


process_data("q2.txt", "q2_output.txt")
