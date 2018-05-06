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
MAT_INST_EXT = ['.min']
SHD_EXT = ['.vs']

def arg_parser():
    parser = argparse.ArgumentParser(description='Shaft Engine ResDB tool')
    parser.add_argument('resourceDirectory', help='Path to the Resource directory.')
    return parser

def file_search(directory, extensions=[], remove_ext=False):
    files = []
    for ext in extensions:
        files += glob.glob(directory+"/**/*"+ext, recursive=True)
    for i, file in enumerate(files):
        files[i] = files[i].replace(directory, "")
        files[i] = files[i].replace('\\', '/')
        if remove_ext == True:
            ext = os.path.splitext(os.path.basename(files[i]))[1]
            files[i] = files[i].replace(ext, "")
    return files

def make_db(directory):
    textures = file_search(directory, extensions=IMAGE_EXT)
    meshes = file_search(directory, extensions=MESH_EXT)
    materials = file_search(directory, extensions=MAT_EXT)
    mat_instances = file_search(directory, extensions=MAT_INST_EXT)
    shaders = file_search(directory, extensions=SHD_EXT, remove_ext=True)
    database = {}
    database['tex'] = textures
    database['mesh'] = meshes
    database['shd'] = shaders
    database['mat'] = materials
    database['min'] = mat_instances
    jsonObj = {}
    jsonObj['in'] = database
    with open(directory+'/ResDB.rdb', 'w') as outfile:
        json.dump(jsonObj, outfile)
    

def main():
    if __name__ == '__main__':
        parser = arg_parser()
        parsed_args = parser.parse_args(sys.argv[1:])
        if os.path.exists(parsed_args.resourceDirectory):
            make_db(parsed_args.resourceDirectory)

main()
