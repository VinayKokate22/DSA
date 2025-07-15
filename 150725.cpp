class Solution {
public:
    bool isValid(string word) {
        set<char>number={'1','2','3','4','5','6','7','8','9','0'};
        set<char>vowel={'a','e','i','o','u'};
        set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm','n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
        bool length=true;
        bool digit=false;
        bool uppercase=false;
        bool lowercase=false;
        bool vowels=false;
        bool con=false;
        if(word.length()<3)length=false;
        for(int i=0;i<word.length();i++){
            if(number.find(word[i])!=number.end()){
                digit=true;
                break;
            }
        }
        for(int i=0;i<word.length();i++){
            if(word[i]>=65 && word[i]<=90){
                uppercase=true;
                break;
            }
        }
        for(int i=0;i<word.length();i++){
            if(word[i]>=97 && word[i]<=122){
                lowercase=true;
                break;
            }
        }
        for(int i=0;i<word.length();i++){
            if(vowel.find(word[i])!=vowel.end()){
                vowels=true;
                break;
            }
            // else if((word[i]>=97 && word[i]<=122) || (word[i]>=65 && word[i]<=90)) con=true;
        }
        for(int i=0;i<word.length();i++){
            if(vowel.find(word[i]+32)!=vowel.end()){
                vowels=true;
                break;
            }
            // else if((word[i]+32>=97 && word[i]+32<=122) || (word[i]+32>=65 && word[i]+32<=90)) con=true;
        }
        for(int i=0;i<word.length();i++){
            if(consonants.find(word[i]+32)!=consonants.end()){
                con=true;
                break;
            }
            // else if((word[i]+32>=97 && word[i]+32<=122) || (word[i]+32>=65 && word[i]+32<=90)) con=true;
        }
        for(int i=0;i<word.length();i++){
            if(consonants.find(word[i])!=consonants.end()){
                con=true;
                break;
            }
            // else if((word[i]+32>=97 && word[i]+32<=122) || (word[i]+32>=65 && word[i]+32<=90)) con=true;
        }
        bool last=true;
       for(int i=0;i<word.length();i++){
            if((word[i]>=58 && word[i]<=64) || (word[i]<48) || (word[i]>=91 && word[i]<=96) || (word[i])>=123){
                last=false;
                break;
            }
            // else if((word[i]+32>=97 && word[i]+32<=122) || (word[i]+32>=65 && word[i]+32<=90)) con=true;
        }
        // cout<<length<<" "<<digit<<" "<<lowercase<<" "<<uppercase<<" "<<vowels<<" "<<con<<endl;
        if(length && (digit || lowercase || uppercase) && vowels && con && last){
            return true;
        }
        return false;
    }
};