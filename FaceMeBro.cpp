
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <iomanip>
#include<vector>
#include <fstream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/tracking.hpp"
#include <chrono> 
#include <map>
using namespace std::chrono;
using namespace cv;
using namespace std;

struct Person {
    int id;
    bool male;
    bool young;
    bool pale;
    bool bigNose;
    bool attractive;

    bool brownHair;
    bool blackHair;
    bool blondeHair;
    bool greyHair;
    bool bald;

    bool noBeard;
    bool mustache;
    bool fiveOclock;
    bool goatee;

    bool wavyHair;
    bool straightHair;

    bool bushyEyebrows;
    bool archedEyebrows;

    bool bigLips;
    bool chubby;
    bool eyeGlasses;
    bool narrowEyes;
    bool highCheekbones;
    bool ovalFace;

    void printPerson() {
        cout << "male: " << this->male << endl;
        cout << "young: " << this->young << endl;
        cout << "pale: " << this->pale << endl;
        cout << "bigNose: " << this->bigNose << endl;
        cout << "attractive: " << this->attractive << endl;
        cout << "brown hair: " << this->brownHair << endl;
        cout << "black hair: " << this->blackHair << endl;
        cout << "blonde hair: " << this->blondeHair << endl;
        cout << "grey hair: " << this->greyHair << endl;
        cout << "bald: " << this->bald << endl;
        cout << "no beard: " << this->noBeard << endl;
        cout << "mustache: " << this->mustache << endl;
        cout << "fiveOclock: " << this->fiveOclock << endl;
        cout << "goatee: " << this->goatee << endl;
        cout << "wavy hair: " << this->wavyHair << endl;
        cout << "straight hair: " << this->straightHair << endl;
        cout << "bushy eyebrows: " << this->bushyEyebrows << endl;
        cout << "arched eyebrows: " << this->archedEyebrows << endl;
        cout << "big lips: " << this->bigLips << endl;
        cout << "chubby: " << this->chubby << endl;
        cout << "glasses: " << this->eyeGlasses << endl;
    }
};



bool convert(string attribute) {
    return attribute == "1";
}

string getAttribute(string line, bool& attribute) {
    int index = line.find_first_of(',');
    attribute = convert(line.substr(0, index));
    return line.substr(index + 1);

}

string skip(string line) {
    int index = line.find_first_of(',');
    return line.substr(index + 1);
}

string addAttributeSet(string line, set<int>& set, int id) {
    int index = line.find_first_of(',');
    if (convert(line.substr(0, index))) {
        set.insert(id);
    }

    return line.substr(index + 1);

}


vector<int> ReadPeopleData(const char* filePath,  Person user) {

    ifstream file(filePath);
    vector<int> matches;
    if (file.is_open()) {
        string lineFromFile;
        string firstLine;

        // get title line, not important
        getline(file, firstLine);
        int max = 0;

        while (!file.eof()) {
            // 1. get Line
            getline(file, lineFromFile);

            Person tempPerson;
            string line;

            // 2. find location of the comma and split into two pieces based on comma location

            int index = lineFromFile.find_first_of(',');
            tempPerson.id = stoi(lineFromFile.substr(0, index));
            line = lineFromFile.substr(index + 1);

            line = getAttribute(line, tempPerson.fiveOclock);
            line = getAttribute(line, tempPerson.archedEyebrows);
            line = getAttribute(line, tempPerson.attractive);
            line = skip(line);
            line = getAttribute(line, tempPerson.bald);
            line = skip(line);
            line = getAttribute(line, tempPerson.bigLips);
            line = getAttribute(line, tempPerson.bigNose);
            line = getAttribute(line, tempPerson.blackHair);
            line = getAttribute(line, tempPerson.blondeHair);
            line = skip(line);
            line = getAttribute(line, tempPerson.brownHair);
            line = getAttribute(line, tempPerson.bushyEyebrows);
            line = getAttribute(line, tempPerson.chubby);
            line = skip(line);
            line = getAttribute(line, tempPerson.eyeGlasses);
            line = getAttribute(line, tempPerson.goatee);
            line = getAttribute(line, tempPerson.greyHair);
            line = skip(line);
            line = getAttribute(line, tempPerson.highCheekbones);
            line = getAttribute(line, tempPerson.male);
            line = skip(line);
            line = getAttribute(line, tempPerson.mustache);
            line = getAttribute(line, tempPerson.narrowEyes);
            line = getAttribute(line, tempPerson.noBeard);
            line = getAttribute(line, tempPerson.ovalFace);
            line = getAttribute(line, tempPerson.pale);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            line = getAttribute(line, tempPerson.straightHair);
            line = getAttribute(line, tempPerson.wavyHair);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            line = skip(line);
            tempPerson.young = convert(line.substr(0, 1));
            line = line.substr(0 + 1);
            //line = getAttribute(line, tempPerson.young);
            int userScore = 0;
            if (user.male == tempPerson.male) {
                userScore++;
            }
            if (user.pale == tempPerson.pale) {
                userScore++;
            }
            if (user.bigNose == tempPerson.bigNose) {
                userScore++;
            }
            if (user.attractive == tempPerson.attractive) {
                userScore++;
            }
            if (user.brownHair == tempPerson.brownHair) {
                userScore++;
            }
            if (user.blackHair == tempPerson.blackHair) {
                userScore++;
            }
            if (user.blondeHair == tempPerson.blondeHair) {
                userScore++;
            }
            if (user.greyHair == tempPerson.greyHair) {
                userScore++;
            }
            if (user.bald == tempPerson.bald) {
                userScore++;
            }
            if (user.noBeard == tempPerson.noBeard) {
                userScore++;
            }
            if (user.mustache == tempPerson.mustache) {
                userScore++;
            }
            if (user.fiveOclock == tempPerson.fiveOclock) {
                userScore++;
            }
            if (user.goatee == tempPerson.goatee) {
                userScore++;
            }
            if (user.wavyHair == tempPerson.wavyHair) {
                userScore++;
            }
            if (user.straightHair == tempPerson.straightHair) {
                userScore++;
            }
            if (user.bushyEyebrows == tempPerson.bushyEyebrows) {
                userScore++;
            }
            if (user.archedEyebrows == tempPerson.archedEyebrows) {
                userScore++;
            }
            if (user.bigLips == tempPerson.bigLips) {
                userScore++;
            }
            if (user.chubby == tempPerson.chubby) {
                userScore++;
            }
            if (user.eyeGlasses == tempPerson.eyeGlasses) {
                userScore++;
            }
            if (user.narrowEyes == tempPerson.narrowEyes) {
                userScore++;
            }
            if (user.highCheekbones == tempPerson.highCheekbones) {
                userScore++;
            }
            if (user.ovalFace == tempPerson.ovalFace) {
                userScore++;
            }
            if (userScore > max) {
                max = userScore;
                matches.clear();
                matches.push_back(tempPerson.id);
                //if the score is equal to the max add it to the list
            }
            else if (userScore == max) {
                matches.push_back(tempPerson.id);
            }

        }
    }
    return matches;
}

void printImage(vector<int> ids) {

    vector<string> windows;
    for (int i = 0; i < ids.size(); i++) {
        string id = to_string(ids[i]);
        while (id.length() < 6) {
            id = "0" + id;
        }
        
        //string imageNum = "000001";
        string imageName = "img_align_celeba/" + id + ".jpg";
        Mat image1 = imread(imageName);

        //check for fail
        if (image1.empty())
        {
            cout << "could not find image" << endl;
            cin.get();
        }

        String windowName = "Your celebrity look alike #" + to_string(i + 1); 

        windows.push_back(windowName);

        //make windoes and fill with image
        namedWindow(windowName, WINDOW_AUTOSIZE);
        resize(image1, image1, Size(450, 500));


        imshow(windowName, image1); 

        moveWindow(windowName, 450 * i, 0);
    }
    waitKey(0);

    //after destroy windows
    for (int j = 0; j < windows.size();j++) {
        destroyWindow(windows[j]);
    }
}


vector<int> useMap(Person user) {


   
   
   vector<int> matches= ReadPeopleData("list_attr_celeba.csv", user);

   
    vector<int>ids;
    for (auto it = 0; it != matches.size() && ids.size() < 3; it++) {
        ids.push_back(matches.at(it));

    }


    return ids;
}

int main() {

    Person user;

    //intro
    cout << "\nWelcome to Face me bro" << endl;
    cout << "Answer the following questions to find celebrities that you look similar to!" << endl;
    cout << endl;


    cout << "What is your gender? \n1.Male \n2.Female" << endl;
    int gender;
    cin >> gender;
    if (gender == 1) {
        user.male = true;
    }
    else {
        user.male = false;
    }

    cout << "Are you young? \n1.Yes \n2.No" << endl;
    int young1;
    cin >> young1;
    if (young1 == 1) {
        user.young = true;
    }
    else {
        user.young = false;
    }

    cout << "Are you Pale? \n1.Yes \n2.No" << endl;
    int pale1;
    cin >> pale1;
    if (pale1 == 1) {
        user.pale = true;
    }
    else {
        user.pale = false;
    }

    cout << "Do you have a big Nose? \n1.Yes \n2.No" << endl;
    int bigNose1;
    cin >> bigNose1;
    if (bigNose1 == 1) {
        user.bigNose = true;
    }
    else {
        user.bigNose = false;
    }

    cout << "Are you attractive? \n1.Yes \n2.No" << endl;
    int attractive1;
    cin >> attractive1;
    if (attractive1 == 1) {
        user.attractive = true;
    }
    else {
        user.attractive = false;
    }

    cout << "What color is you hair? \n1.Brown \n2.Black \n3.Blonde \n4.grey \n5.Bald \n6.Other" << endl;
    int hair;
    cin >> hair;
    if (hair == 1) {
        user.brownHair = true;
        user.blackHair = false;
        user.blondeHair = false;
        user.greyHair = false;
        user.bald = false;
    }
    else if (hair == 2) {
        user.brownHair = false;
        user.blackHair = true;
        user.blondeHair = false;
        user.greyHair = false;
        user.bald = false;
    }
    else if (hair == 3) {
        user.brownHair = false;
        user.blackHair = false;
        user.blondeHair = true;
        user.greyHair = false;
        user.bald = false;
    }
    else if (hair == 4) {
        user.brownHair = false;
        user.blackHair = false;
        user.blondeHair = false;
        user.greyHair = true;
        user.bald = false;
    }
    else if (hair == 5) {
        user.brownHair = false;
        user.blackHair = false;
        user.blondeHair = false;
        user.greyHair = false;
        user.bald = true;
    }
    else {
        user.brownHair = false;
        user.blackHair = false;
        user.blondeHair = false;
        user.greyHair = false;
        user.bald = false;
    }

    cout << "Describe your hair type? \n1.Wavy \n2.Straight \n3.Other" << endl;
    int hairType;
    cin >> hairType;
    if (hairType == 1) {
        user.wavyHair = true;
        user.straightHair = false;
    }
    else if (hairType == 2) {
        user.wavyHair = false;
        user.straightHair = true;
    }
    else {
        user.wavyHair = false;
        user.straightHair = false;
    }

    if (gender == 1) {
        cout << "Describe your facial hair? \n1.None \n2.Mustache \n3.Five o'clock shadow \n4.Goatee" << endl;
        int beard;
        cin >> beard;
        if (beard == 1) {
            user.noBeard = true;
            user.mustache = false;
            user.fiveOclock = false;
            user.goatee = false;
        }
        else if (beard == 2) {
            user.noBeard = false;
            user.mustache = true;
            user.fiveOclock = false;
            user.goatee = false;
        }
        else if (beard == 3) {
            user.noBeard = false;
            user.mustache = false;
            user.fiveOclock = true;
            user.goatee = false;
        }
        else if (beard == 4) {
            user.noBeard = false;
            user.mustache = false;
            user.fiveOclock = false;
            user.goatee = true;
        }
    }
    else {
        user.noBeard = true;
        user.mustache = false;
        user.fiveOclock = false;
        user.goatee = false;
    }

    cout << "Do you have high cheekbones? \n1.Yes \n2.No" << endl;
    int cheek;
    cin >> cheek;
    if (cheek == 1) {
        user.highCheekbones = true;
    }
    else {
        user.highCheekbones = false;
    }

    cout << "Do you have an oval face? \n1.Yes \n2.No" << endl;
    int face;
    cin >> face;
    if (face == 1) {
        user.ovalFace = true;
    }
    else {
        user.ovalFace = false;
    }

    cout << "Are you chubby? \n1.Yes \n2.No" << endl;
    int chubby;
    cin >> chubby;
    if (chubby == 1) {
        user.chubby = true;
    }
    else {
        user.chubby = false;
    }

    cout << "Do you wear glasses? \n1.Yes \n2.No" << endl;
    int glasses;
    cin >> glasses;
    if (glasses == 1) {
        user.eyeGlasses = true;
    }
    else {
        user.eyeGlasses = false;
    }


    cout << "Describe your eyebrows? \n1.Bushy \n2.Arched \n3.Other" << endl;
    int eyebrows;
    cin >> eyebrows;
    if (eyebrows == 1) {
        user.bushyEyebrows = true;
        user.archedEyebrows = false;
    }
    else if (eyebrows == 2) {
        user.bushyEyebrows = false;
        user.archedEyebrows = true;
    }
    else {
        user.bushyEyebrows = false;
        user.archedEyebrows = false;
    }

    cout << "Do you have big lips? \n1.Yes \n2.No" << endl;
    int bigLips;
    cin >> bigLips;
    if (bigLips == 1) {
        user.bigLips = true;
    }
    else {
        user.bigLips = false;
    }

    cout << "Do you have narrow eyes? \n1.Yes \n2.No" << endl;
    int eyes;
    cin >> eyes;
    if (eyes == 1) {
        user.narrowEyes = true;
    }
    else {
        user.narrowEyes = false;
    }

    //finding the correct images
    //using sets
   
    vector<int> ids = useMap(user);

    //printing image
    if (ids.size() > 0) {
            cout << "\nDisplaying Images... \nPress any key to close images." << endl;
            printImage(ids);
     }
    else {
        cout << "There were no celebrities with these traits. " << endl;
    }
      


    return 0;
}
