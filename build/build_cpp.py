import os
import shutil
import pathlib

def main():
    folder_name = input("Enter folder name: ")
    build_dir = pathlib.Path(__file__).parent.resolve()
    source_path = build_dir / "template_cpp"
    destination_path = build_dir.parent.absolute() / "C++" / folder_name
    print(source_path)
    print(destination_path)
    try:
        shutil.copytree(source_path, destination_path)
    except FileExistsError:
        print("The directory already exists. Use a different name or delete the original folder.")



if __name__ == "__main__":
    main()
