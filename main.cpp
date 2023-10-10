#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;



class Document {
private:
    Document() {}
    vector<string> words;
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        //vector<string> words;
        if (myFileStrm.is_open()) {
            //vector<string> words;
            string word, feedVector;
            int i = 0;
            while (getline(myFileStrm,theLine,'\n')) {
                istringstream lineStringStrm(theLine);


                //cout << theLine.size() << endl;
                feedVector.append(theLine);
                feedVector.append(" "); //end the line with a space

                //when the paragraph is over, create a part of the vector
                //the vector is made of paragraphs
                if (theLine.size() == 0){
                    words.push_back(feedVector);
                    feedVector = "";
                    i = i + 1;

                }

            }

            //add the last paragraph
            words.push_back(feedVector);
            feedVector = "";
            myFileStrm.close();
        }
    }

    void prettyPrint() {
        string paragraph = "";

        for (int i = 0; i < words.size(); i++){//iterate through every paragraph
            paragraph = words[i];
            if (paragraph.size() <= 80){ //check if the paragraph is under 80 characters, if so print it
                cout << paragraph << endl << endl;
            }
            else{
                int j = 0;
                int start = 0;
                int end = 0;
                while (j < paragraph.size()){ //find the most recent occurence of a space and set it equal to end
                    if (paragraph[j] == ' '){
                        end = j;
                        //cout << "!!!!!";
                    }
                    if (j % 80 == 0 && j != 0){
                        for (int i = start; i < end; i++){ // output the characters from the startpoint to the end
                            cout << paragraph[i];
                        }
                        start = end + 1; // set the new startpoint



                        cout << endl;
                    }
                    j = j+1;
                }
                for (int i = start; i < paragraph.size(); i++){//print the last line
                    cout << paragraph[i];
                }
                cout << endl << endl;

            }
        }



        // print out the document, making sure that
        // no line of a paragraph is longer than 80 chars
    }
};

//this edit is for the project example

int main() {
    cout << "I am editing this and going to pull it to my main branch" << endl;
    cout << "I am adding this as well" << endl;
    Document myDoc("G.txt");
    myDoc.prettyPrint();
    return 0;
}
