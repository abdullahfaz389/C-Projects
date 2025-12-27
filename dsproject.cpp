#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
using namespace std;

class voter{
    public:
    int age;
    string cnic,region,name,partyname;
    bool voted;
    voter* left,*right;
    voter(){
        left=right=nullptr;
        voted=false;
    }
};

class voterbst{
    private:
    int pti,pmln,pp,jui,mlq,tlp;
    voter* root;
    public:
    voterbst(){
        pti=0;
        pmln=0;
        pp=0;
        jui=0;
        mlq=0;
        tlp=0;
        root=nullptr;
    }

    voter* createvoter(string n,int a,string cnic,string r){
        voter* newvoter=new voter();
        newvoter->name=n;
        newvoter->age=a;
        newvoter->cnic=cnic;
        newvoter->region=r;
        newvoter->left=nullptr;
        newvoter->right=nullptr;
        return newvoter;
    }

    voter* insertvoter(voter* newvoter,string n,int a,string cnic,string r){
        if(newvoter==nullptr){
            newvoter=createvoter(n,a,cnic,r);
        }
        else if(cnic<newvoter->cnic){
            newvoter->left=insertvoter(newvoter->left,n,a,cnic,r);
        }
        else if(cnic>newvoter->cnic){
            newvoter->right=insertvoter(newvoter->right,n,a,cnic,r);
        }
        return newvoter;
    }

    void insert(){
        int age;
        string cnic,region,name;
        while (true)
        {
            cout << "Enter Name: ";
            getline(cin,name);

            if(name.length()==0){
                cout<<"Name reqquired! try again:"<<endl;
                continue;
            }
            bool valid =true;
            for(int i=0;i<name.length();i++){
                if(!(isalpha(name[i])||name[i]==' ')){
                    valid=false;
                    break;
                }
                }
                if(!valid){
                    cout<<"Name must contain only alphabets and spaces! Try again."<<endl;
                    continue;
                }
            break;
        }

        while(1){
            string ageStr;
            cout << "Enter age: ";
            getline(cin, ageStr);

            if(ageStr.length()==0){
                cout<<"Age reqquired! Try again:"<<endl;
                continue;
            }
            bool valid = true;
            for(int i=0;i<ageStr.length();i++){
                if(!(isdigit(ageStr[i]))){
                    valid = false;
                    break;
                }
            }

            if(!valid){
                cout << "Invalid input! Digits only." << endl;
                continue;
            }

            age = stoi(ageStr);

            if(age < 18){
                cout << "For vote casting, age must be 18 or older!" << endl;
                continue;
            }
            break;
        }

        while(1){
            cout <<"Enter Region (Provinces only): ";
            getline(cin,region);

            for(int i=0;i<region.length();i++){
                region[i]=toupper(region[i]);
            }
            if(region=="KPK"||region=="FATA"||region=="PUNJAB"||region=="SINDH"||region=="BALOCHISTAN"||region=="ISL"||region=="GB"){
                break; 
            } 
            else{
                cout<<"Invalid region! Please enter a valid province."<<endl;
            }
        }

        while (1){
            cout<<endl;
            cout<<"Start up of CNIC numbers of all provinces:KPK(1),Fata(2),Punjab(3),Sindh(4),Balochistan(5),ISL(6),GB(7)."<<endl;
            cout<<"Enter CNIC Number: ";
            getline(cin,cnic);

            //Convert lower case to upper case.
            for(int i=0;i<region.length();i++){
                region[i]=toupper(region[i]);
            }

            //validation of CNIC and Region.
            if(cnic.length()!=13){
                cout<<"Invalid CNIC length! Must be 13 character!Try again."<<endl;
                continue;
            }
            char s=cnic[0];
            bool validRegion = false;

            if(region=="KPK" && s=='1'){
                validRegion = true;
            }
            else if(region=="FATA" && s=='2'){
                validRegion = true;
            }
            else if(region=="PUNJAB" && s=='3'){
                validRegion = true;
            }
            else if(region=="SINDH" && s=='4'){
                validRegion = true;
            }
            else if(region=="BALOCHISTAN" && s=='5'){ 
                validRegion = true;
            }
            else if(region=="ISL" && s=='6'){
                validRegion = true;
            }
            else if(region=="GB" && s=='7'){
                validRegion = true;
            }
            else{
                cout << "CNIC does not match selected region." << endl;
                continue;
            }

            //check duplicate.
            if(searchvoter(root,cnic)==nullptr){
                break;
            }
            else{
                searchvoter(root, cnic);
                cout<<"Voter with CNIC "<<"'"<<cnic<<"'"<<" is already registered!\n";
                continue;
            }
            }

            root=insertvoter(root,name,age,cnic,region);

            //save record of registers voters
            ofstream outfile("Register_voters.txt",ios::app);
            if(!outfile){
            cout<<"Unable to open this file!"<<endl;
            }
            outfile<<"----Register voter----"<<endl;
            outfile<<"Name: "<<name<<endl;
            outfile<<"Age: "<<age<<endl;
            outfile<<"Region: "<<region<<endl;
            outfile<<"CNIC: "<<cnic<<endl;
         
            outfile.close();
    }

    voter* searchvoter(voter* temp,string key){
        if(temp==nullptr){
            return nullptr;  //temp;
        }
        else if(key==temp->cnic){
            return temp;
        }
        else if(key<temp->cnic){
            return searchvoter(temp->left,key);
        }
        else{
            return searchvoter(temp->right,key);
        }
    }

    void search(){
        string cnic;  
        while(true){
            cout<<"Enter CNIC Number: ";
            getline(cin, cnic);

            if(cnic.length() == 0){
                cout<<"CNIC required! Try again."<<endl;
                continue;
            }
            if(cnic.length() != 13){
                cout<<"CNIC must be exactly 13 digits!"<<endl;
                continue;
            }

            bool valid = true;
            for(int i = 0; i < cnic.length(); i++){
                if(!isdigit(cnic[i])){   
                    valid = false;
                    break;
                }
            }
            if(!valid){
                cout<<"CNIC must contain digits only! Try again."<<endl;
                continue;
            }
            break;  
        }

        voter* s = searchvoter(root, cnic);

        if(s == nullptr){
            cout<<"Voter not found!"<<endl;
        }
        else{
            cout<<"CNIC Number: "<<s->cnic<<endl;
            cout<<"Name: "<<s->name<<endl;
            cout<<"Region: "<<s->region<<endl;
        }
    }


    voter* findMin(voter* node){
        while(node&&node->left!=nullptr)
        node=node->left;
        return node;
    }

    voter* deleteVoter(voter* node,string cnic){
        if (node==nullptr){
            cout<<"Voter not found!"<<endl;
            return node;
        }

        if(cnic<node->cnic){
            node->left=deleteVoter(node->left,cnic);
        }
        else if(cnic>node->cnic){
            node->right=deleteVoter(node->right,cnic);
        }
        else{
            if(node->voted){
                cout<<"Cannot delete! Voter has already voted."<<endl;
                return node;
            }
            if(node->left==nullptr&&node->right==nullptr){
                delete node;
                cout<<"Voter deleted successfully."<<endl;
                return nullptr;
            }
            else if(node->left==nullptr){
                voter* temp=node->right;
                delete node;
                cout<<"Voter deleted successfully."<<endl;
                return temp;
            }
            else if(node->right==nullptr){
                voter* temp=node->left;
                delete node;
                cout<<"Voter "<<temp->name<<" deleted successfully."<<endl;
                return temp;
            }

            voter* temp=findMin(node->right);
            node->cnic=temp->cnic;
            node->name=temp->name;
            node->age=temp->age;
            node->region=temp->region;
            node->voted=temp->voted;
 
            node->right = deleteVoter(node->right, temp->cnic);
        }
        return node;
    }

    void del(){
        string cnic;
        cout<<"Enter CNIC number:";
        getline(cin,cnic);
        root=deleteVoter(root,cnic);
    }

    void updatevoter(){
        string nname, cnic, nregion;
        int nage;

        cout<<"Enter CNIC of voter to update: ";
        getline(cin,cnic);

        voter* v=searchvoter(root,cnic);
        if(v==nullptr){
            cout<<"Voter not found!"<<endl;
            return;
        }
        if(v->voted){
            cout<<"Cannot update! Voter has already voted."<<endl;
            return;
        }
 
        // update name
        string nchoice;
        cout<<"You want to update your Name: (yes/no): ";
        getline(cin,nchoice);
        if(nchoice=="yes"){
            cout<<"Enter your New Name: ";
            getline(cin,nname);
            v->name=nname;
            cout<<"Name updated successfully!"<<endl;
        }
 
        // update age
        string achoice;
        cout<<"You want to update your Age: (yes/no): ";
        getline(cin,achoice);
        if(achoice=="yes"){
            cout<<"Enter your New Age: ";
            cin>>nage;
            cin.ignore(); // flush newline
            v->age=nage;
            cout<<"Age updated successfully!"<<endl;
        }
    }

    void processvote(string c,string pn){
    voter* v = searchvoter(root,c);

        if (v == nullptr) {
            cout << "Voter not found.\n";
        }
        else if (v->voted) {
            cout << v->name << " has already voted.\n";
        }
        else {
            cout << v->name << " voted successfully for "<<pn<< endl;
            v->voted = true;

            //Count vote.
            if(pn=="PTI"||pn=="pti"){
                pti++;
            }
            else if(pn=="PMLN"||pn=="pmln"){
                pmln++;
            }
            else if(pn=="PP"||pn=="pp"){
                pp++;
            }
            else if(pn=="JUI"||pn=="jui"){
                jui++;
            }
            else if(pn=="MLQ"||pn=="mlq"){
                mlq++;
            }
            else if(pn=="TLP"||pn=="tlp"){
                tlp++;
            }
            else{
                cout<<"Unknown party name!"<<endl;
            }
        }

        // --- Save vote record to file ---
        ofstream voteoutFile("VotesRecord.txt", ios::app);  // append mode
        if(!voteoutFile){
            cout<<"Unable to open this file!"<<endl;
            return;
        }
            voteoutFile<<"Voter CNIC: "<<v->cnic<<endl;
            voteoutFile<<"Name: " << v->name<<endl;
            voteoutFile<<"Age: "<<v->age<<endl;
            voteoutFile<<"Region: "<<v->region<<endl;
            voteoutFile<<"Party: " << pn << endl;
            voteoutFile.close();
        
    }

    void readVotesRecord() {
        ifstream infile("VotesRecord.txt"); 
        if (!infile){
            cout<<"No votes have been recorded yet!"<<endl;
            return;
        }

        string line;
        cout<<"\n--- Votes Record ---" << endl;
        while(getline(infile, line)){ 
            cout<<line<<endl;
        }

        infile.close();
    }

    
    void displayVoters(voter* node){
        if(node==nullptr){
            return;
        }
        displayVoters(node->left); 
        cout <<"Name: "<<node->name<<endl;
        cout <<"Age: "<<node->age<<endl;
        cout <<"Region: "<<node->region<<endl;
        cout <<"CNIC: "<<node->cnic<<endl;
        cout <<"-----------------------"<<endl;
        displayVoters(node->right); 
    }

    void displayAllVoters(){
        if (root==nullptr){
            cout<<"No voters registered yet!"<<endl;
            return;
        }
        displayVoters(root);
    }


    void result(){
        cout<<"\n--- TOTAL VOTES ---"<<endl;
        cout<<"PTI :"<<pti<<endl;
        cout<<"PMLN :"<<pmln<<endl;
        cout<<"PP :"<<pp<<endl;
        cout<<"JUI :"<<jui<<endl;
        cout<<"MLQ :"<<mlq<<endl;
        cout<<"TLP :"<<tlp<<endl;

        //results stores in file
        ofstream resultoutfile("Result.txt",ios::app);
        if(!resultoutfile){
            cout<<"Unable to open this file!"<<endl;
            return;
        }
        resultoutfile<<"\n--- TOTAL VOTES ---"<<endl;
        resultoutfile<<"PTI :"<<pti<<endl;
        resultoutfile<<"PMLN :"<<pmln<<endl;
        resultoutfile<<"PP :"<<pp<<endl;
        resultoutfile<<"JUI :"<<jui<<endl;
        resultoutfile<<"MLQ :"<<mlq<<endl;
        resultoutfile<<"TLP :"<<tlp<<endl;
        resultoutfile.close();
    }

    void regvotersinfile(){
        ifstream infile("Register_voters.txt");
        if (!infile) {
            cout<<"File not found!"<<endl;
            return;
        }
        string line;
        while(getline(infile,line)) {
            cout<<line<<endl;
        }
        infile.close();
    }

    void resultinfile(){
        ifstream infile("Result.txt");
        if (!infile) {
            cout<<"File not found!"<<endl;
            return;
        }
        string line;
        while(getline(infile,line)) {
            cout<<line<<endl;
        }
        infile.close();
    }

    bool isRegistered(string cnic){
        return (searchvoter(root, cnic) != nullptr);
    }

};

class queuenode{
    public:
    string cnic;
    queuenode* next;
    queuenode(string c){
        cnic=c;
        next=nullptr;
    }
};
class votingqueue{
    private:
    queuenode* front,*rear;
    public:
    votingqueue(){
        front=rear=nullptr;
    }
    void enqueue(string cnic){
        queuenode* newnode=new queuenode(cnic);
        if(rear==nullptr){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void enqueuehelper(voterbst &b){
        string c;
        while(true){
            cout<<"Enter CNIC Number: ";
            getline(cin,c);

            if(c.length()==0){
                cout<<"CNIC required! Try again."<<endl;
                continue;
            }

            if(c.length()!=13){
                cout<<"CNIC must be exactly 13 digits!"<<endl;
                continue;
            }

            bool valid=true;
            for(int i=0;i<c.length();i++){
                if(!isdigit(c[i])){
                    valid=false;
                    break;
                }
            }
            if(!valid){
                cout<<"CNIC must contain digits only!"<<endl;
                continue;
            }

            if(!b.isRegistered(c)){
                cout<<"Voter not registered! Cannot add to queue."<<endl;
                continue;
            }

            enqueue(c);
            cout<<"Voting request added successfully."<<endl;
            break;
        }
    }

    string dequeue(){
        if(front==nullptr){
            return"";
        }
        queuenode* temp=front;
        string c=temp->cnic;
        front=front->next;

        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
        return c;
    }

    bool isempty(){
        return (front==nullptr);
    }
};

int main(){
    voterbst b;
    votingqueue q;

    while(true){
        cout<<"==========================================="<<endl;
        cout << "  --- Voting System Menu ---" << endl;
        cout << "1. Register Voters." << endl;
        cout << "2. Delete or Update Voter." << endl;
        cout << "3. Add Voting Request." << endl;
        cout << "4. Process vote." << endl;
        cout << "5. Search Voter." << endl;
        cout << "6. Show Results." << endl;
        cout << "7. Display All Voters." << endl;
        cout << "8. Read record of register voters." << endl;
        cout << "9. Read Votes Cast Record." << endl;
        cout << "10. Read Results." << endl;
        cout << "11. Exit." << endl;
        cout<<"==========================================="<<endl;

        // ---------- SAFE MENU INPUT ----------
        string input;
        cout << "Enter your choice: ";
        getline(cin, input);

        if(input.length() == 0){
            cout << "Input required!" << endl;
            continue;
        }

        bool valid = true;
        for(int i = 0; i < input.length(); i++){
            if(!isdigit(input[i])){
                valid = false;
                break;
            }
        }

        if(!valid){
            cout << "Invalid input! Numbers only allowed." << endl;
            continue;
        }

        int choice = stoi(input);
        // -------------------------------------

        switch(choice){
        case 1:
            b.insert();
            cout << "Voter Registered Successfully!" << endl;
            break;

        case 2:{
            string sub;
            cout << "1. Delete Voter." << endl;
            cout << "2. Update Voter." << endl;
            cout << "Enter your choice: ";
            getline(cin, sub);

            if(sub != "1" && sub != "2"){
                cout << "Invalid choice!" << endl;
                break;
            }

            int subchoice = stoi(sub);
            if(subchoice == 1){
                b.del();
            }
            else{
                b.updatevoter();
            }
            break;
        }

        case 3:
            q.enqueuehelper(b);
            break;

        case 4:
            if(q.isempty()){
                cout << "No voters in queue." << endl;
            }
            else{
                string partyname;
                cout << "Enter party name (PTI,PMLN,PP,MLQ,JUI,TLP): ";
                getline(cin, partyname);

                for(int i = 0; i < partyname.length(); i++){
                    partyname[i] = toupper(partyname[i]);
                }

                string id = q.dequeue();
                b.processvote(id, partyname);
            }
            break;

        case 5:
            b.search();
            break;

        case 6:
            b.result();
            break;

        case 7:
            b.displayAllVoters();
            break;

        case 8:
            b.regvotersinfile();
            break;

        case 9:
            b.readVotesRecord();
            break;

        case 10:
            b.resultinfile();
            break;

        case 11:
            cout << "Exiting system..." << endl;
            return 0;

        default:
            cout << "Invalid menu choice!" << endl;
        }
    }

    return 0;
}
 