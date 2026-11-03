import re

class Transition:
    def __init__(self, from_state, label, to_state):
        self.from_state = from_state
        self.label = label
        self.to_state = to_state

def parse_set(string):
    tokens = re.split('[ ,{}]', string)
    return [token for token in tokens if token != '']

def fa_to_rg(transitions, initial_state, final_states):
    productions = []
    for t in transitions:
        productions.append((t.from_state.upper(), f'{t.label} {t.to_state.upper()}'))
        if t.to_state in final_states:
            productions.append((t.from_state.upper(), t.label))

    start = initial_state.upper()
    if initial_state in final_states:
        new_start = start + "'"
        copies = [(new_start, right) for left, right in productions if left == start]
        productions = [(new_start, 'ε')] + copies + productions
        start = new_start

    return start, productions



if __name__ == '__main__':
    states = set()
    alphabet = set()
    transitions = []
    initial_state = None
    final_states = set()

    input_filename = input('Enter your input file name!!!!\n𝑀𝓎 𝒾𝓃𝓅𝓊𝓉 𝒻𝒾𝓁𝑒 𝓃𝒶𝓂𝑒: ')
    output_filename = input('Enter your output file name!!!!\n𝑀𝓎 𝑜𝓊𝓉𝓅𝓊𝓉 𝒻𝒾𝓁𝑒 𝓃𝒶𝓂𝑒: ')

    try:
        with open(input_filename, encoding='utf-8') as file:
            lines = file.readlines()

            for line in lines:
                line = line.strip()
                if line == '':
                    continue

                if line.startswith('Q = '):
                    states = set(parse_set(line.removeprefix('Q = ')))
                elif line.startswith('Σ = '):
                    alphabet = set(parse_set(line.removeprefix('Σ = ')))
                elif line.startswith('F = '):
                    final_states = set(parse_set(line.removeprefix('F = ')))
                elif line.startswith('q0 = '):
                    initial_state = line.removeprefix('q0 = ').strip()
                elif line.startswith('d('):
                    left, to_state = line.removeprefix('d(').split('=')
                    from_state, label = left.strip().removesuffix(')').split(',')
                    transitions.append(Transition(from_state.strip(), label.strip(), to_state.strip()))
                else:
                    print(f'Stupid: {line}')

        start, productions = fa_to_rg(transitions, initial_state, final_states)

        nonterminals = sorted(s.upper() for s in states)
        if start not in nonterminals:
            nonterminals.insert(0, start)

        with open(output_filename, 'w', encoding='utf-8') as file:
            file.write(f'N = {{{", ".join(nonterminals)}}}\n')
            file.write(f'Σ = {{{", ".join(sorted(alphabet))}}}\n')
            file.write(f'S = {start}\n')
            file.write('P:\n')
            for left, right in productions:
                file.write(f'    {left} -> {right}\n')

        print('\nDone 💯')
                    

    except FileNotFoundError:
        print('...file not found...')