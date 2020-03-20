rm -rf $(git rev-parse --show-toplevel)/build
mkdir $(git rev-parse --show-toplevel)/build
cd $(git rev-parse --show-toplevel)/build
conan install $(git rev-parse --show-toplevel)/ --build=missing
cmake $(git rev-parse --show-toplevel)/
cd $(git rev-parse --show-toplevel)/build
cmake --build $(git rev-parse --show-toplevel)/build