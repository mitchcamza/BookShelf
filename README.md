# COS3711-03-01
A Book Management Application

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
	•	CMakeLists.txt: Main CMake configuration file for building the project.
	•	src/: Source files for the project.
        •	CMakeLists.txt: Cmake configuration file for building the project (without tests).
        •	main.cpp: Entry point of the application.
        •	author.h, author.cpp: Class representing an author.
        •	book.h, book.cpp: Class representing a book.
        •	filewriter.h, filewriter.cpp: Class for writing text to a file.
        •	bookwriter.h, bookwriter.cpp: Class for serializing book objects to XML.
        •	bookfactory.h, bookfactory.cpp: Class for deserializing book objects from XML.
        •	bookinput.h, bookinput.cpp: Handles book input data.
        •	booktablemodel.h, booktablemodel.cpp: Custom model representing book data.
        •	bookproxymodel.h, bookproxymodel.cpp: Custom proxy model for filtering book data.
        •	mainwindow.h, mainwindow.cpp: Main window class for the GUI.
        •	resources.qrc: A resource file containing resources used.
	•	tests/: Unit tests for the project.
        •	CMakeLists.txt: Cmake configuration file for building the tests.
        •	testauthor.cpp, testauthor.h: Unit tests for the Author class.
        •	testbook.cpp, testbook.h: Unit tests for the Book class.
        •	testfilewriter.cpp, testfilewriter.h: Unit tests for the FileWriter class.
        •	testbookwriter.cpp, testbookwriter.h: Unit tests for the BookWriter class.
        •	testbookfactory.cpp, testbookfactory.h: Unit tests for the BookFactory class.
        •	testbooktablemodel.cpp, testbooktablemodel.h: Unit tests for the BookTableModel class.
        •	testbookproxymodel.cpp, testbookproxymodel.h: Unit tests for the BookProxyModel class.
        •	docs/: Documentation files.
        •	README.md: Project overview and information.
        •	user_manual.md: User manual for the application.
        •	api_reference.md: API reference documentation for the classes and methods used in the project.

## Usage
The application allows users to manage a collection of books, including adding new books, filtering the list, and exporting or importing the collection as an XML file.

### Adding a Book

	1.	Open the application.
	2.	Use the “New Book” button to add a new book.
	3.	Enter the book’s title, authors, publication date, and ISBN.
	4.	Save the book to add it to the collection.

### Filtering Books

	•	Use the search bar to filter books by title or author name. The displayed results will update as you type.

### Exporting Books

	1.	Click on “Export Book List” in the file menu.
	2.	Choose a destination and file name for the XML file.
	3.	Save the file to export the current book list.

### Authors

	•	Mitch Campbell

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
