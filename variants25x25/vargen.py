# Modify the obfuscation function to handle new variables and structure for 25x25 Sudoku
def obfuscate_25x25_code(code):
    # Generate new variable/function names to replace old ones
    replacements = {
        'Sudoku': 'MegaPuzzle' + str(random.randint(100, 999)),
        'grid': 'largeMatrix' + str(random.randint(1, 99)),
        'rowUsed': 'rowMarkers' + str(random.randint(1, 99)),
        'colUsed': 'colMarkers' + str(random.randint(1, 99)),
        'boxUsed': 'boxMarkers' + str(random.randint(1, 99)),
        'charmapper': 'charToInt' + str(random.randint(1, 99)),
        'intmapper': 'intToChar' + str(random.randint(1, 99)),
        'isSafe': 'canPlace' + str(random.randint(1, 99)),
        'printGrid': 'showGrid' + str(random.randint(1, 99)),
        'solveSudoku': 'resolveGrid' + str(random.randint(1, 99)),
        'populateGrid': 'initializeGrid' + str(random.randint(1, 99)),
        'solveAndPrint': 'solveAndDisplay' + str(random.randint(1, 99))
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
    methods = ['canPlace', 'showGrid', 'resolveGrid']
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

# Generate the variants for the latest code
latest_variants = []
for _ in range(7):
    latest_variants.append(obfuscate_25x25_code(latest_code))

# Return a snippet of each variant to ensure uniqueness
latest_variant_snippets = [variant.split('\n')[:5] for variant in latest_variants]
latest_variant_snippets
