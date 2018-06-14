import os
import sys
import shutil
import glob
import subprocess

if len(sys.argv) != 2:
    print("Usage: python clean.py FOLDER_NAME")
    exit(-1)

JUDGE_PATH = 'JUDGE'
TEMP_PATH = '__temp__'
ROOT_PATH = sys.argv[1]


def is_file_matched(file_a, file_b):
    data_a = None
    data_b = None

    with open(file_a, 'r') as fin:
        data_a = '\n'.join([l.strip() for l in fin.readlines()])

    with open(file_b, 'r') as fin:
        data_b = '\n'.join([l.strip() for l in fin.readlines()])

    return data_a and data_b and data_a == data_b


def judge_heap(source_heap, data_path, is_cpp=False, point=10):
    global JUDGE_PATH, TEMP_PATH
    compile_cmd = 'g++ %s %s %s -o %s -w -I %s -O2' % (
        os.path.join(JUDGE_PATH, 'test_heap.cpp'),
        source_heap,
        os.path.join(JUDGE_PATH, 'graph.c'),
        os.path.join(TEMP_PATH, 'heap.exe'),
        JUDGE_PATH
    )

    if 0 != subprocess.call(compile_cmd.split(), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        return 0

    output_path = os.path.join(data_path, 'output.txt')
    answer_path = os.path.join(data_path, 'output.example.txt')

    if os.path.isfile(output_path):
        os.remove(output_path)

    run_cmd = '%s %s' % (os.path.join(TEMP_PATH, 'heap.exe'), data_path)

    print(run_cmd)

    try:
        if 0 != subprocess.call(run_cmd.split(), timeout=2, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
            return 0
    except Exception as e:
        return 0

    if not os.path.isfile(output_path):
        return 0

    if not is_file_matched(output_path, answer_path):
        return 0

    return point


def judge_disjoint_set(source_graph, data_path, is_cpp=False, point=10):
    global JUDGE_PATH, TEMP_PATH
    compile_cmd = 'g++ %s %s %s -o %s -w -I %s -O2' % (
        os.path.join(JUDGE_PATH, 'test_disjoint_set.cpp'),
        os.path.join(JUDGE_PATH, 'heap.c'),
        source_graph,
        os.path.join(TEMP_PATH, 'graph.exe'),
        JUDGE_PATH
    )

    if 0 != subprocess.call(compile_cmd.split(), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        return 0

    output_path = os.path.join(data_path, 'output.txt')
    answer_path = os.path.join(data_path, 'output.example.txt')

    if os.path.isfile(output_path):
        os.remove(output_path)

    run_cmd = '%s %s' % (os.path.join(TEMP_PATH, 'graph.exe'), data_path)

    try:
        if 0 != subprocess.call(run_cmd.split(), timeout=2, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
            return 0
    except Exception as e:
        return 0

    if not os.path.isfile(output_path):
        return 0

    if not is_file_matched(output_path, answer_path):
        return 0

    return point


def judge_kruskal_set(source_heap, source_graph, data_path, is_cpp=False, point=20):
    global JUDGE_PATH, TEMP_PATH
    compile_cmd = 'g++ %s %s %s -o %s -w -I %s -O2' % (
        os.path.join(JUDGE_PATH, 'test_kruskal.cpp'),
        source_heap,
        source_graph,
        os.path.join(TEMP_PATH, 'kruskal.exe'),
        JUDGE_PATH
    )

    if 0 != subprocess.call(compile_cmd.split(), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        return 0

    output_path = os.path.join(data_path, 'output.txt')
    answer_path = os.path.join(data_path, 'output.example.txt')

    if os.path.isfile(output_path):
        os.remove(output_path)

    run_cmd = '%s %s' % (os.path.join(TEMP_PATH, 'kruskal.exe'), data_path)

    try:
        if 0 != subprocess.call(run_cmd.split(), timeout=2, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
            return 0
    except Exception as e:
        return 0

    if not os.path.isfile(output_path):
        return 0

    if not is_file_matched(output_path, answer_path):
        return 0

    return point


def compile(file_path):
    global TEMP_PATH, JUDGE_PATH

    if not file_path or not os.path.isfile(file_path):
        return False

    file_name = os.path.split(file_path)[-1]
    output_path = os.path.join(TEMP_PATH, file_name + '.o')

    cmd = None
    if file_name.endswith('.c') or file_name.endswith('.cc') or file_name.endswith('.cpp'):
        cmd = 'g++ -o %s -c %s -I %s -w' % (output_path, file_path, JUDGE_PATH)
    else:
        return False

    with open(file_path + ".log.txt", 'w') as fout:
        returncode = subprocess.call(cmd.split(), stderr=fout)
        if returncode != 0:
            print(file_path)
            return False

    return True


def judge_student(submit_path):
    source_graph = None
    source_heap = None
    is_cpp = False

    for log in glob.iglob(os.path.join(submit_path, '*log*')):
        os.remove(log)

    for source in glob.iglob(os.path.join(submit_path, 'graph.c*')):
        source_graph = source

    for source in glob.iglob(os.path.join(submit_path, 'heap.c*')):
        source_heap = source

    # if source_graph:
    #     if compile(source_graph):
    #         if not source_graph.endswith('.c'):
    #             is_cpp = True
    #     else:
    #         source_graph = None
    #
    # if source_heap:
    #     if compile(source_heap):
    #         if not source_graph.endswith('.c'):
    #             is_cpp = True
    #     else:
    #         source_heap = None

    points = {
        'proper_submit': 0,
        'heap': 0,
        'disjoint_set': 0,
        'kruskal': 0,
        'total': 0
    }

    if source_heap:
        points['heap'] += judge_heap(source_heap, os.path.join(JUDGE_PATH, 'data_heap_small'), is_cpp)
        points['heap'] += judge_heap(source_heap, os.path.join(JUDGE_PATH, 'data_heap_large'), is_cpp)

    if source_graph:
        points['disjoint_set'] += judge_disjoint_set(source_graph, os.path.join(JUDGE_PATH, 'data_disjoint_set_small'),
                                                     is_cpp)
        points['disjoint_set'] += judge_disjoint_set(source_graph, os.path.join(JUDGE_PATH, 'data_disjoint_set_large'),
                                                     is_cpp)

    if source_heap and source_graph:
        points['kruskal'] += judge_kruskal_set(source_heap, source_graph,
                                               os.path.join(JUDGE_PATH, 'data_kruskal_small'), is_cpp)
        points['kruskal'] += judge_kruskal_set(source_heap, source_graph,
                                               os.path.join(JUDGE_PATH, 'data_kruskal_large'), is_cpp)

    points['total'] = points['heap'] + points['disjoint_set'] + points['kruskal']
    if points['total'] > 0:
        points['proper_submit'] += 20
        points['total'] += 20

    return points


def main():
    global ROOT_PATH, TEMP_PATH

    for trash in glob.iglob('__temp*__'):
        shutil.rmtree(trash, ignore_errors=True)

    scores = []
    score_titles = ['student_id', 'proper_submit', 'heap', 'disjoint_set', 'kruskal', 'total']

    for folder in os.listdir(ROOT_PATH):
        student_path = os.path.join(ROOT_PATH, folder)
        submit_path = os.path.join(student_path, '__submit__')
        if not os.path.isdir(student_path) or not os.path.isdir(submit_path):
            continue

        shutil.rmtree(TEMP_PATH, ignore_errors=True)
        TEMP_PATH = '__temp%s__' % student_path[-9:]
        os.mkdir(TEMP_PATH)

        point = judge_student(submit_path)
        point['student_id'] = int(student_path[-9:])
        scores.append(point)

    with open(os.path.join(ROOT_PATH, 'score_sheet.tsv'), 'w')  as fout:
        fout.write('\t'.join(score_titles) + "\n")

        for score in scores:
            for title in score_titles:
                fout.write('%d\t' % score[title])
            fout.write("\n")


if __name__ == "__main__":
    main()
