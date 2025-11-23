class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = seats.size();
        int i=0;
        int j=0;
        int moves=0;
        while(i<n){
            if(seats[i]!=students[j]) moves+=abs(seats[i]-students[j]);
            i++;
            j++;

        }
        return moves;
    }
};