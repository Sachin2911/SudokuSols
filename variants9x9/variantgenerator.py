import random

def obfuscate_code(code):
    # Generate new variable/function names to replace old ones
    replacements = {
        'Sudoku': 'Puzzle' + str(random.randint(100, 999)),
        'grid': 'matrix' + str(random.randint(1, 99)),
        'rowUsed': 'rowsFlag' + str(random.randint(1, 99)),
        'colUsed': 'colsFlag' + str(random.randint(1, 99)),
        'boxUsed': 'boxesFlag' + str(random.randint(1, 99)),
        'isSafe': 'isValid' + str(random.randint(1, 99)),
        'printGrid': 'displayMatrix' + str(random.randint(1, 99)),
        'solveSudoku': 'resolvePuzzle' + str(random.randint(1, 99)),
        'populateGrid': 'fillMatrix' + str(random.randint(1, 99)),
        'solveAndPrint': 'resolveAndShow' + str(random.randint(1, 99))
    }

    # Apply the replacements
    for old, new in replacements.items():
        code = code.replace(old, new)

    # Add some random whitespace
    lines = code.split('\n')
    for i in range(len(lines)):
        if random.choice([True, False]):
            lines[i] = '    ' + lines[i]

    # Randomly reorder private methods
    methods = ['isValid', 'displayMatrix', 'resolvePuzzle']
    random.shuffle(methods)
    for method in methods:
        method_code = ''
        inside_method = False
        new_lines = []
        for line in lines:
            if method + str(random.randint(1, 99)) in line:
                inside_method = not inside_method
            if inside_method:
                method_code += line + '\n'
            else:
                new_lines.append(line)
        lines = new_lines + [method_code]

    return '\n'.join(lines)

# Generate the first variant
variant1 = obfuscate_code(original_code)
variant1
