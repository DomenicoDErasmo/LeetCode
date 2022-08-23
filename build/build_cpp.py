import os
import shutil
import pathlib

def main():
    folder_name = input("Enter folder name: ")
    source_path = pathlib.Path(__file__).parent.resolve()
    destination_path = source_path.parent.absolute() / "C++" / folder_name
    try:
        shutil.copytree(source_path, destination_path)
    except FileExistsError:
        print("The directory already exists. Use a different name or delete the original folder.")



if __name__ == "__main__":
    main()
