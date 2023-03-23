# Mallorca

Console app request to login and display the returned


## General

- The program developed and tested on Ubuntu 22.04
- The application depend on "libcurl"
- Main function include examples of use
- Flask app to simulate login page


## Installation

Install the "libcurl" library needed:

```
sudo apt install libcurl4 libcurl4-gutls-dev
```

For the Flask app install flask in python virtual environment:
```
python3 -m venv .venv
source .venv/bin/activate
python -m pip install flask
```


## Running

Run the python flask app:
```
python app.py
```

Compile the CPP program:
```
make compile
```

Build the CPP program:
```
make build
```

Run the CPP program:
```
./main.exe
```

Clean the CPP artifacts:
```
clean clean
```


## Code structure

### Requests class

This class wrap the "libcurl" library. To perform GET and POST requests.

Two main function:

- "requestGet" perform GET request:
    - Uses mUrl1, mUrl2
    - Change the mChunk

- "requestPost" perform POST request:
    - Uses mUrl1, mUrl2, mNameTitle, mNameValue, mPassTitle, mPassValue
    - Change the mChunk


### Parser class

This class parse the html, and search for the form with password, and find the field names.


### Change examples

The "main.cpp" include few examples:

- Example1 - perform GET request from "http://localhost:5000/login". The server can be run using flask app.

- Example2 - perform POST request from "http://localhost:5000/login", while setting the POST data.
The server can be run using flask app.

- Example3 - perform GET request from "http://testphp.vulnweb.com/login.php".

- Example4 - perform POST request from "http://testphp.vulnweb.com/userinfo.php", while setting the POST data. 

- Example5 - perform GET request from "http://testphp.vulnweb.com/login.php". Parse the return HTML for the POST data. 
Then perform POST request.

To run different example edit the main function:
```cpp
int main() {
    cout << "Main start" << endl;
    int res = example5();
    return res;
}
```


## The assessment

Using modern C++ build a console app that does a request to simulate login to "http://testphp.vulnweb.com/login.php"
and display the returned HTML page.  You can use any C++ open-source library of your liking. 

Bonus points:
- Good code structure
- Use of cmake
- Use of GIT
- Use of modern C++ features

Deliverable:
- Provide a working application
- Provide source code in any public git such as GitHub or BitBucket
- Provide a markdown readme file with general information about the app and steps how to launch/build your application
