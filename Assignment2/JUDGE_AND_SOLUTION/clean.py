import sys
import os
import zipfile
import shutil
import glob
import codecs
from chardet.universaldetector import UniversalDetector


def clean_directory(root_path):
    for name in os.listdir(root_path):
        path = os.path.join(root_path, name)
        begin = name.find('_201') + 1
        if begin < 0 or os.path.isdir(path):
            continue

        end = begin + 9
        student_id = name[begin:end]
        folder = os.path.join(root_path, student_id)
        if not os.path.isdir(folder):
            os.mkdir(folder)

        shutil.move(path, os.path.join(folder, name))


def unzip(student_path):
    for file in os.listdir(student_path):
        file_path = os.path.join(student_path, file)
        if not file_path.lower().endswith('.zip'):
            continue

        zip = zipfile.ZipFile(file_path)
        zip.extractall(student_path)


def collect_and_clean(student_path):
    temp_path = os.path.join(student_path, "__submit__")
    if not os.path.isdir(temp_path):
        os.mkdir(temp_path)

    def find_and_move(pattern, name):
        # for file in glob.iglob(os.path.join(student_path, pattern), recursive=True):
        #     if file.upper().find('README') >= 0:
        #         continue
        #
        #     target_name = os.path.join(temp_path, name)
        #     shutil.move(file, target_name)

        for file in glob.iglob(os.path.join(student_path, '**', pattern), recursive=True):
            if file.upper().find('README') >= 0:
                continue

            target_name = os.path.join(temp_path, name)
            shutil.move(file, target_name)

    find_and_move('*graph.c', 'graph.c')
    find_and_move('*heap.c', 'heap.c')
    find_and_move('*graph.cpp', 'graph.cpp')
    find_and_move('*heap.cpp', 'heap.cpp')
    find_and_move('*.docx', 'report.docx')
    find_and_move('*.pdf', 'report.pdf')
    find_and_move('*.docc', 'report.c')
    find_and_move('*.txt', 'info.txt')


def convert_encoding(student_path):
    temp_path = os.path.join(student_path, "__submit__")
    for file_name in os.listdir(temp_path):
        file_path = os.path.join(temp_path, file_name)
        if file_name.lower().endswith('.c') or file_name.lower().endswith('.cpp') or file_name.lower().endswith('.cc'):
            detector = UniversalDetector()
            detector.reset()
            with open(os.path.join(temp_path, file_name), 'rb') as fin:
                for line in fin.readlines():
                    detector.feed(line)
                    if detector.done:
                        break

            detector.close()
            source_encoding = detector.result['encoding']
            target_encoding = 'utf-8'
            if source_encoding == target_encoding:
                continue

            data = None
            with codecs.open(file_path, 'r', source_encoding) as fin:
                data = fin.read()

            if not data:
                print(file_path)
                continue

            with codecs.open(file_path, 'w', target_encoding) as fout:
                fout.write(data)


def main():
    if len(sys.argv) != 2:
        print("Usage: python clean.py FOLDER_NAME")
        exit(-1)

    root_path = sys.argv[1]
    clean_directory(root_path)

    for folder in os.listdir(root_path):
        student_path = os.path.join(root_path, folder)
        if not os.path.isdir(student_path):
            continue

        unzip(student_path)
        collect_and_clean(student_path)
        convert_encoding(student_path)


if __name__ == "__main__":
    main()
