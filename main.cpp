#include <iostream>
#include <fstream>
#include <vector>

// Use the stb_image and stb_image_write libraries for reading and writing image files
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// The maximum message size that can be stored in the image
const int MAX_MESSAGE_SIZE = 1000;

// Loads an image from a file and returns the pixel data as a 3D array of unsigned chars (rgb values)
unsigned char *loadImage(const char *fileName, int &width, int &height, int &channels)
{
  unsigned char *image = stbi_load(fileName, &width, &height, &channels, STBI_rgb);
  if (image == nullptr)
  {
    std::cerr << "Error: failed to load image " << fileName << std::endl;
    exit(1);
  }
  return image;
}

// Saves an image to a file from a 3D array of unsigned chars (rgb values)
void saveImage(const char *fileName, const unsigned char *image, int width, int height, int channels)
{
  if (!stbi_write_png(fileName, width, height, channels, image, width * channels))
  {
    std::cerr << "Error: failed to save image " << fileName << std::endl;
    exit(1);
  }
}

int main()
{
  // Load the input image
  int width, height, channels;
  unsigned char *image = loadImage("input.png", width, height, channels);

  // Read the message to be hidden in the image
  std::cout << "Enter the message to be hidden in the image (max " << MAX_MESSAGE_SIZE << " characters): ";
  std::string message;
  std::getline(std::cin, message);
  if (message.size() > MAX_MESSAGE_SIZE)
  {
    std::cerr << "Error: message is too long, maximum allowed is " << MAX_MESSAGE_SIZE << " characters" << std::endl;
    exit(1);
  }

  // Convert the message to a vector of bytes
  std::vector<unsigned char> messageBytes(message.begin(), message.end());
  messageBytes.push_back('\0'); // add a null terminator to the end of the message

  // Encode the message length at the beginning of the image
  int messageLength = messageBytes.size();
  image[0] = (messageLength >> 24) & 0xff;
  image[1] = (messageLength >> 16) & 0xff;
  image[2] = (messageLength >> 8) & 0xff;
  image[3] = messageLength & 0xff;

  // Encode the message bytes in the rest of the image
  for (int i = 0; i < messageLength; i++)
  {
    image[4 + i] = messageBytes[i];
  }

  // Save the output image
  saveImage("output.png", image, width, height, channels);

  std::cout << "Successfully encoded message in image" << std::endl;

  // Free the image data
  stbi_image_free(image);

  return 0;
}
