#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOCUMENTS 5

// Sample document data structure
struct Document {
    int id;
    char title[100];
    char content[500];
};

// Sample documents
struct Document documents[MAX_DOCUMENTS] = {
    {1, "Document 1", "This is the content of Document 1."},
    {2, "Document 2", "Here is the content of Document 2."},
    {3, "Document 3", "Content for Document 3 goes here."},
    {4, "Document 4", "This is Document 4's content."},
    {5, "Document 5", "The content of Document 5 is here."},
};

// Function to search for documents using Boolean operators
void booleanSearch(const char* query) {
    printf("Search Results for: %s\n", query);

    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        bool match = false;

        // Perform Boolean search using strstr
        if (strstr(documents[i].title, query) != NULL || strstr(documents[i].content, query) != NULL) {
            match = true;
        }

        // Print the matching documents
        if (match) {
            printf("Document %d: %s\n", documents[i].id, documents[i].title);
        }
    }
}

int main() {
    char query[100];

    printf("Enter your Boolean search query (e.g., 'AND', 'OR', 'NOT', etc.): ");
    fgets(query, sizeof(query), stdin);

    // Remove the newline character from the user input
    query[strcspn(query, "\n")] = '\0';

    booleanSearch(query);

    return 0;
}
