#include <algorithm>
#include <chrono> // NOLINT (build/c++11)
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
// TODO: Define your Sighting class here
// The class should store speed, brightness, and calculated signature
// Signature formula: ceil((speed * brightness) / 10)
// Include constructor, destructor, and necessary operators
class Sighting {
public:
  Sighting() : speed(0), brightness(0), signature(0) {}

  Sighting(int s, int b) {
    speed = s;
    brightness = b;
    double cell = (speed * brightness) / 10.0;
    signature = (int)(cell + 0.9999);
  }

  int GetSignature() const {
    return signature;
  }

  // Custom comparison used for sorting sightings
  bool operator<(const Sighting &other) const {
    if (signature != other.signature) {
      return signature < other.signature;
    }
    else {
      return speed < other.speed;
    }
            
  }                                          

private:
    int speed;
    int brightness;
    int signature;
};
// TODO: Implement linear search function
// int linearSearch(std::vector<Sighting> sightings, std::vector<int> signatures)
int linearSearch(std::vector<Sighting> sightings, std::vector<int> signatures) {
  if (sightings.size() == 0 || signatures.size() == 0) {
    return 0;
  }

  // Sort signatures so we can remove duplicates
  for (unsigned int i = 0; i < signatures.size(); i++) {
    for (unsigned int j = i + 1; j < signatures.size(); j++) {
      if (signatures[j] < signatures[i]) {
        int t = signatures[i];
        signatures[i] = signatures[j];
        signatures[j] = t;
      }
    }
  }

  // Build a unique list of signatures
  vector<int> uniq;
  for (unsigned int i = 0; i < signatures.size(); i++) {
    if (i == 0 || signatures[i] != signatures[i - 1]) {
      uniq.push_back(signatures[i]);
    }
  }

  int hit = 0;

  // Check if each unique signature appears in any sighting
  for (unsigned int i = 0; i < uniq.size(); i++) {
    int target = uniq[i];
    bool found = false;

    for (unsigned int j = 0; j < sightings.size(); j++) {
      if (found == false && sightings[j].GetSignature() == target) {
        found = true;
      }
    }

    if (found == true) {
      hit = hit + 1;
    }
  }

  return hit;
}
// TODO: Implement binary search function  
// int binarySearch(std::vector<Sighting> sorted_sightings, std::vector<int> signatures)
int binarySearch(std::vector<Sighting> sorted_sightings, std::vector<int> signatures) {
  if (sorted_sightings.size() == 0 || signatures.size() == 0) {
    return 0;
  }

  // Simple selection sort to sort sightings
  for (unsigned int i = 0; i < sorted_sightings.size(); i++) {
    unsigned int p = i;
    for (unsigned int j = i + 1; j < sorted_sightings.size(); j++) {
      if (sorted_sightings[j] < sorted_sightings[p]) {
        p = j;
      }
    }
    if (p != i) {
      Sighting tmp = sorted_sightings[i];
      sorted_sightings[i] = sorted_sightings[p];
      sorted_sightings[p] = tmp;
    }
  }

  // Extract signatures from the sorted sightings
  vector<int> sigs;
  for (unsigned int i = 0; i < sorted_sightings.size(); i++) {
    sigs.push_back(sorted_sightings[i].GetSignature());
  }

  for (unsigned int i = 0; i < signatures.size(); i++) {
    for (unsigned int j = i + 1; j < signatures.size(); j++) {
      if (signatures[j] < signatures[i]) {
        int t = signatures[i]; signatures[i] = signatures[j]; signatures[j] = t;
      }
    }
  }

  // Unique signatures
  vector<int> uniq;
  for (unsigned int i = 0; i < signatures.size(); i++) {
    if (i == 0 || signatures[i] != signatures[i - 1]) {
      uniq.push_back(signatures[i]);
    }
  }

  int hit = 0;

  for (unsigned int i = 0; i < uniq.size(); i++) {
    int target = uniq[i];
    int left = 0;
    int right = (int)sigs.size() - 1;
    bool found = false;

    while (left <= right && !found) {
      int mid = (left + right) / 2;
      if (sigs[mid] == target) {
        found = true;
      }
      else if (sigs[mid] < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }

    if (found) {
      hit = hit + 1;
    }
  }

    return hit;
}


int main(int argc, char *argv[]) {
  // TODO: Check command line arguments

  // TODO: Open and validate input files

  // TODO: Read sighting data from file
  // Parse each line containing speed and brightness values
  // Create Sighting objects and store in vector

  // TODO: Read signature data from file
  // Parse each line containing signature values
  // Store in vector of integers

  // User prompt for search method
  std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
  char search_type;
  bool validSelection = false;

  // Input validation loop
  while (!validSelection) {
    std::cin >> search_type;
    if (search_type != 'l' && search_type != 'b') {
      std::cerr << "Incorrect choice" << std::endl;
    } else {
      validSelection = true;
    }
  }

  // TODO: Initialize timing variables
  // std::chrono::high_resolution_clock::time_point start;
  // start = std::chrono::high_resolution_clock::now();

  // TODO: Implement search logic based on user choice
  switch (search_type) {
    case 'l':
      // TODO: Call linear search function
      break;
    case 'b':
      // TODO: Sort sightings vector first
      // TODO: Call binary search function
      break;
  }

  // TODO: Calculate and display timing

  // TODO: Write result to output file

  // TODO: Close files and clean up

  return 0;
}
