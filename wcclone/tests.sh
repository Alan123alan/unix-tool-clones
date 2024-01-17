#Expected results VS wcclone program results

#Echo the first line and it's word count from wc and wcclone
echo $(head -n 1 test.txt)
echo "expected results => " $(head -n 1 test.txt | wc -w)
head -n 1 test.txt > temp.txt
echo "program results =>" $(./wcclone -w temp.txt)
#Echo the second line and it's word count from wc and wcclone
echo $(tail -n +2 test.txt | head -n 1)
echo "expected results =>" $(tail -n +2 test.txt | head -n 1 | wc -w)
tail -n +2 test.txt | head -n 1 > temp.txt
echo "program results =>" $(./wcclone -w temp.txt)
#Echo the third line and it's word count from wc and wcclone
echo $(tail -n +3 test.txt | head -n 1)
echo "expected results =>" $(tail -n +3 test.txt | head -n 1 | wc -w)
tail -n +3 test.txt | head -n 1 > temp.txt
echo "program results =>" $(./wcclone -w temp.txt)

