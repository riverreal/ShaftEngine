"""
Shaft Engine Resource DB maker tool

Creates a resource database from the Resource folder.

"""

import os
import sys
import argparse
import glob
import json
from os import listdir
from os.path import isfile, join

#extensions
IMAGE_EXT = ['.jpg','.png']
MESH_EXT = ['.obj', '.fbx']
MAT_EXT = ['.mat']

def arg_parser():
    parser = argparse.ArgumentParser(description='Shaft Engine ResDB tool')
    parser.add_argument('resourceDirectory', help='Path to the Resource directory.')
    return parser

def file_search(directory, extensions=[]):
    files = []
    for ext in extensions:
        files += glob.glob(directory+"/**/*"+ext, recursive=True)
    for i, file in enumerate(files):
        files[i] = files[i].replace(directory, "")
        files[i] = files[i].replace('\\', '/')
    return files

def make_db(directory):
    textures = file_search(directory, extensions=IMAGE_EXT)
    meshes = file_search(directory, extensions=MESH_EXT)
    materials = file_search(directory, extensions=MAT_EXT)
    database = {}
    database['tex'] = textures
    database['mesh'] = meshes
    database['mat'] = materials
    with open(directory+'/ResDB.rdb', 'w') as outfile:
        json.dump(database, outfile)
    

def main():
    if __name__ == '__main__':
        parser = arg_parser()
        parsed_args = parser.parse_args(sys.argv[1:])
        if os.path.exists(parsed_args.resourceDirectory):
            make_db(parsed_args.resourceDirectory)

main()
