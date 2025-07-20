#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Simple Base62 characters for encoding the short URL
const string base62_chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

class URLShortener {
private:
    // Maps to store long to short and short to long
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    int counter = 0; // Auto-increment ID for each new long URL

    // Converts an integer ID to a Base62 string
    string encodeBase62(int num) {
        string shortURL;
        while (num > 0) {
            shortURL = base62_chars[num % 62] + shortURL;
            num /= 62;
        }
        // Pad short URLs to length 6 for uniformity
        while (shortURL.length() < 6) {
            shortURL = "0" + shortURL;
        }
        return shortURL;
    }

public:
    // Shortens a long URL into a short one
    string shortenURL(const string& longURL) {
        // Return existing short URL if already shortened
        if (longToShort.find(longURL) != longToShort.end()) {
            return "short.ly/" + longToShort[longURL];
        }

        // Generate new short code
        string code = encodeBase62(counter++);
        longToShort[longURL] = code;
        shortToLong[code] = longURL;

        return "short.ly/" + code;
    }

    // Expands a short URL to its original long URL
    string expandURL(const string& shortURL) {
        // Extract code from "short.ly/abc123"
        string code = shortURL.substr(shortURL.find_last_of("/") + 1);

        if (shortToLong.find(code) != shortToLong.end()) {
            return shortToLong[code];
        } else {
            return "Error: Short URL not found!";
        }
    }
};

// ----------------------
// Example usage
// ----------------------
int main() {
    URLShortener shortener;

    string longURL1 = "https://www.example.com/articles/how-to-learn-cpp";
    string longURL2 = "https://chat.openai.com/gpt-4";

    // Shorten URLs
    string short1 = shortener.shortenURL(longURL1);
    string short2 = shortener.shortenURL(longURL2);

    // Display results
    cout << "Original: " << longURL1 << "\nShortened: " << short1 << endl;
    cout << "Original: " << longURL2 << "\nShortened: " << short2 << endl;

    // Expand back
    cout << "\nExpanding short URLs:" << endl;
    cout << short1 << " => " << shortener.expandURL(short1) << endl;
    cout << short2 << " => " << shortener.expandURL(short2) << endl;

    // Try expanding a non-existent short URL
    cout << "\nInvalid short URL:" << endl;
    cout << "short.ly/xyz999 => " << shortener.expandURL("short.ly/xyz999") << endl;

    return 0;
}
