 # Project 1: File Compression and Decompression using Run-Length Encoding (RLE)
This project involves creating a C++ program that reads the contents of a file, compresses the data using the Run-Length Encoding (RLE) algorithm, and writes the compressed result to another file. Additionally, the program performs the reverse operation—decompression—restoring the original content from the compressed file.

 ## Key Features:
                Compression: Reads a file and compresses its content using RLE.
                Decompression: Restores the original content from the compressed file.
                File I/O: Handles reading from and writing to files.
 # Project 2: Weather Forecasting System
This program is a simple weather app that allows users to:
Add locations by name, latitude, and longitude.
List saved locations to see what has been added.
Fetch and display weather data for any location using the OpenWeather API (requires an API key).
Export weather data to both CSV (Excel-style) and JSON formats.
Exit the app when done.
 ## Key Parts:
            Location Management: Save locations and view them later.
            Weather Forecasting: Fetches live weather data (temperature, wind speed, humidity) from OpenWeather based on the location.
            Data Exporting: Saves weather information to files for future reference.
 ## How it Works:
The program displays a menu where users select options by typing numbers. Weather data is fetched from the internet using libcurl and formatted using nlohmann/json. It exports the weather data entered into two file types: .csv and .json.

 # Project 3: Contact Management System
This C++ program implements a "Contact Management System" that allows users to add, view, and delete contacts.

## Key Features:
                Each contact consists of a name and a phone number, stored in a Contact class.
                The ContactManager class manages a list of contacts using a vector, providing functions to:
                Add new contacts
                Display all contacts
                Delete a contact by name
 # Project 4: Simple HTTP Server
This project implements a simple HTTP server in C++ that serves an HTML file to clients. The server listens for incoming connections, handles each client in a separate thread, and responds with the contents of a specified HTML file.

 ## Key Features:
                Multithreading: Each client connection is handled in a separate thread for concurrent processing.
                HTTP Response Handling: The server responds with an HTTP status code and serves the contents of an HTML file.
                Error Handling: If the requested file is not found, the server responds with a 404 Not Found message.
 ## How it Works:
                Socket Creation: A TCP socket is created to listen for incoming connections.
                Binding and Listening: The server binds to port 8080 and listens for incoming client requests.
                Client Handling: When a client connects, a new thread is spawned to handle the request:
                The server attempts to read the contents of index.html.
                If the file is found, it sends a 200 OK response along with the file's content.
                If the file is not found, it sends a 404 Not Found response.
Thread Management: Each client thread is detached to allow independent operation without waiting for it to finish.
