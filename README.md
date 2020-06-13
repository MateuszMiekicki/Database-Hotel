# Booking management system 

The reservation management system is a side-project that I wanted to explore the possibilities of tests and performance tests. 
The system will consist of separate, replaceable modules that will allow you to incorporate it into other projects. 

## Installation

Use the CMake building system

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=<DEBUG/RELEASE> -DENABLE_TESTS=<ON/OFF>
make
```

## Usage

The exact use of each module can be found in the folder "test".

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
