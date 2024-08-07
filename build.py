import os
import shutil
import subprocess

def main():
    result = subprocess.run(["clear"], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Make failed with error:\n{result.stderr}")
        return
    else:
        print("clear screen")

    
    build_dir = "build"

    # Check if build directory exists
    if os.path.exists(build_dir):
        # Remove the build directory if it exists
        print(f"Removing existing build directory: {build_dir}")
        shutil.rmtree(build_dir)
    
    # Create a new build directory
    print(f"Creating build directory: {build_dir}")
    os.makedirs(build_dir)
    
    # Change to the build directory
    os.chdir(build_dir)
    
    # Run cmake ..
    print("Running cmake ..")
    result = subprocess.run(["cmake", ".."], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"CMake configuration failed with error:\n{result.stderr}")
        return
    
    # Run make
    print("Running make")
    result = subprocess.run(["make", "-j"], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Make failed with error:\n{result.stderr}")
        return

    print("Build completed successfully")

if __name__ == "__main__":
    main()