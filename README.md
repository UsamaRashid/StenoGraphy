# Image STENOGRAPHY Encoder

This is a README file for the Image Message Encoder project. The project involves encoding a message into an image using the least significant bits (LSB) technique.

## Description

The purpose of this project is to encode a message into an image using the LSB technique. The LSB technique involves modifying the least significant bits of the pixel values in an image to store the message data. This allows the message to be hidden in the image without significantly affecting its visual appearance.

## Dependencies

To run this project, you need to have the following dependencies:

- C++ compiler
- stb_image library
- stb_image_write library

## Usage

1. Ensure that you have the necessary dependencies installed on your system.
2. Compile the source code using a C++ compiler.
3. Run the compiled binary.

Upon running the program, you will be prompted to enter the message that you want to hide in the image. The maximum allowed message size is 1000 characters. Once you provide the message, the program will encode it into the image file "input.png" and save the resulting image as "output.png".

## Input Image

The program expects an input image file named "input.png" in the same directory as the executable. Make sure to place the image file in the correct location before running the program.

## Output Image

The program will generate an output image named "output.png" that contains the hidden message. This image will be saved in the same directory as the executable.

## Message Encoding

The program encodes the message into the image using the LSB technique. Here's how the encoding process works:

1. The program loads the input image from the file.
2. It reads the message that you provided and converts it into a vector of bytes.
3. The length of the message (in bytes) is encoded in the first four bytes of the image. The most significant byte is stored at index 0, and the least significant byte is stored at index 3.
4. The message bytes are then encoded in the remaining bytes of the image, starting from index 4.
5. The modified image with the encoded message is saved as the output image.

## License

This project is licensed under the [MIT License](LICENSE).
