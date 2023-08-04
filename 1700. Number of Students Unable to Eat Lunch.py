# 
# Created by leeyu on 2022/10/6.
# 
from typing import List

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        while sandwiches:
            if sandwiches[0] not in students:
                break
            if students[0] == sandwiches[0]:
                del students[0]
                del sandwiches[0]
            else:
                students.append(students[0])
                del students[0]



        return len(students)
    
if __name__ == '__main__':
    S = Solution()
    num = S.countStudents([1,1,0,0], [0,1,0,1])
    print(num)