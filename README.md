# COS3711-03-02
A Book Management Application

[![Build](https://github.com/mitchcamza/COS3711-03/actions/workflows/build.yml/badge.svg)](https://github.com/mitchcamza/COS3711-03/actions/workflows/build.yml)

## Project Overview

- **Book Management**: Classes for representing and managing books (`Book`, `Author`, etc.) and functionality to read from and write to XML files.
- **Graphical User Interface**: A Qt Widgets-based GUI to interact with the book data.
- **CMake Build System**: The project uses CMake to manage the build process.

## Features

- **Book Management**: Add, view, and manage a collection of books.
- **User Interface**: Intuitive GUI for interacting with the book collection.
- **Book Factory**: The `BookFactory` class utilizes the factory pattern for managaing the creation of books.
- **Custom Models**: The application uses `BookTableModel` to represent book data and `BookProxyModel` to filter and sort the data.
- **XML Serialization**: Export book data to an XML file using the `BookWriter` class.
- **Filter Books**: Filter books based on author name or book title.

![alt text](<Screenshot 2024-09-08 at 16.04.51.png>)

## Getting Started

### Prerequisites

- **Qt**: Ensure you have Qt installed (version 5 or 6).
- **CMake**: Version 3.5 or higher.
- **C++ Compiler**: Ensure you have a C++17 compatible compiler.

### Getting the Source Code

#### Option 1: Download the Release
1. **Download the Release**: Navigate to the [Releases](https://github.com/mitchcamza/COS3711-03-01/releases) page of this repository.
2. **Select the Latest Release**: Download the release with the version number formatted as `yyyy.mm.dd.<question_number>`.
3. **Extract the Files**: Extract the downloaded archive to your desired location.

#### Option 2: Clone the Repository
1. **Clone the Repository**:
    ```bash
    git clone https://github.com/mitchcamza/COS3711-03-01
    cd COS3711-03-01
    ```
2. **Checkout the COS3711-03-01 branch**
   ```bash
   git checkout COS3711-03-01

## Building the Project

### Option 1: Using Qt Creator
1. Open the top-level CMakeLists.txt file in Qt Creator.
2. Configure the project.
3. Build and run the project.

### Option 2: Using the command line (on Linux)
1.	**Navigate to the Project Directory**: Open a terminal or command prompt and navigate to the extracted project directory.
2.	**Make sure the build script is executable**: On Linux:
    ```bash 
    sudo chmod +x ./build_and_run.sh
    ```
3. **Run the build script**:
    ```bash
    sudo ./build_and_run.sh
    ```

## Project Structure
```
MyProject/
├── CMakeLists.txt        # Root CMake file for the entire project
├── src/                  # Source directory
│   ├── CMakeLists.txt    # CMake file for source code
│   ├── main.cpp
│   ├── author.h
│   ├── author.cpp
│   ├── book.h
│   ├── book.cpp
│   ├── bookfactory.h
│   ├── bookfactory.cpp
│   ├── bookinput.h
│   ├── bookinput.cpp
│   ├── bookproxymodel.h
│   ├── bookproxymodel.cpp
│   ├── booktablemodel.h
│   ├── booktablemodel.cpp
│   ├── bookwriter.h
│   ├── bookwriter.cpp
│   ├── filewriter.h
│   ├── filewriter.cpp
│   ├── mainwindow.h
│   └── mainwindow.cpp

├── tests/                # Tests directory
│   ├── CMakeLists.txt    # CMake file for tests
│   ├── testauthor.h
│   ├── testauthor.cpp
│   ├── testbook.h
│   ├── testbook.cpp
│   ├── testbookfactory.h
│   ├── testbookfactory.cpp
│   ├── testbookproxymodel.h
│   ├── testbookproxymodel.cpp
│   ├── testbooktablemodel.h
│   ├── testbooktablemodel.cpp
│   ├── testbookwriter.h
│   ├── testbookwriter.cpp
│   ├── testfilewriter.h
│   └── testfilewriter.cpp
```

## Usage
The application allows users to manage a collection of books, including adding new books, filtering the list, and exporting or importing the collection as an XML file.

### Adding a Book

	1.	Open the application.
	2.	Use the “New Book” button to add a new book.
	3.	Enter the book’s title, authors, publication date, and ISBN.
	4.	Save the book to add it to the collection.

### Filtering Books

    - Use the search bar to filter books by title or author name. The displayed results will update as you type.

### Exporting Books

	1.	Click on “Export Book List” in the file menu.
	2.	Choose a destination and file name for the XML file.
	3.	Save the file to export the current book list.

## Author
Mitch Campbell

[LinkedIn](https://www.linkedin.com/in/mitch-campbell-93b18919b/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
