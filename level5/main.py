import os

# Function to check if we can place a desk vertically at (row, col)
def can_place_vertical(layout, row, col):
    if row + 1 >= len(layout) or layout[row][col] != '.' or layout[row + 1][col] != '.':
        return False

    # Check surrounding cells to avoid touching
    for r in range(-1, 3):
        for c in range(-1, 2):
            new_row, new_col = row + r, col + c
            if 0 <= new_row < len(layout) and 0 <= new_col < len(layout[0]) and layout[new_row][new_col] == 'X':
                return False
    return True

# Function to check if we can place a desk horizontally at (row, col)
def can_place_horizontal(layout, row, col):
    if col + 1 >= len(layout[0]) or layout[row][col] != '.' or layout[row][col + 1] != '.':
        return False

    # Check surrounding cells to avoid touching
    for r in range(-1, 2):
        for c in range(-1, 3):
            new_row, new_col = row + r, col + c
            if 0 <= new_row < len(layout) and 0 <= new_col < len(layout[0]) and layout[new_row][new_col] == 'X':
                return False
    return True

# Function to place a desk vertically
def place_vertical(layout, row, col):
    layout[row][col] = 'X'
    layout[row + 1][col] = 'X'

# Function to place a desk horizontally
def place_horizontal(layout, row, col):
    layout[row][col] = 'X'
    layout[row][col + 1] = 'X'

# Function to generate the room layout based on given dimensions and number of desks
def generate_room_layout(length, width, desks):
    layout = [['.' for _ in range(length)] for _ in range(width)]  # Initialize the room with empty spaces
    desk_count = 0

    for row in range(width):
        for col in range(length):
            # Check if we can place either a vertical or horizontal desk
            can_place_h = can_place_horizontal(layout, row, col)
            can_place_v = can_place_vertical(layout, row, col)

            # Prefer placing horizontally if possible
            if desk_count < desks and can_place_h:
                place_horizontal(layout, row, col)
                desk_count += 1
            elif desk_count < desks and can_place_v:
                place_vertical(layout, row, col)
                desk_count += 1

            # Early exit if we have placed all desks
            if desk_count >= desks:
                break
        if desk_count >= desks:
            break

    return layout

# Function to write the room layouts to an output file
def write_room_layouts_to_file(output_file_name, all_layouts):
    with open(output_file_name, 'w') as out_file:
        for layout in all_layouts:
            for row in layout:
                out_file.write(''.join(row) + '\n')
            out_file.write('\n')  # Separate rooms with a blank line

def main():
    # Input and output file names
    input_file_name = "level5_example.in"  # Input file name
    output_file_name = "level5_example.out"  # Output file name

    if not os.path.exists(input_file_name):
        print("Could not open the input file!")
        return

    with open(input_file_name, 'r') as in_file:
        N = int(in_file.readline().strip())  # Number of rooms

        all_layouts = []  # To store layouts for all rooms

        for _ in range(N):
            length, width, desks = map(int, in_file.readline().strip().split())
            # Generate the room layout
            layout = generate_room_layout(length, width, desks)
            all_layouts.append(layout)

    # Write the layouts to the output file
    write_room_layouts_to_file(output_file_name, all_layouts)

if __name__ == "__main__":
    main()
