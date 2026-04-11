class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        pair = [(i, sorted(s)) for i,s in enumerate(strs)]
        groups = []

        while len(pair):
            gi = []
            index, sorted_str = pair.pop()
            gi.append(index)
            
            to_pop = []
            for i,s in pair:
                if sorted_str == s:
                    gi.append(i)
                    to_pop.append((i,s))

            for i in to_pop:
                pair.pop(pair.index(i))
            groups.append(gi)

        ret = []
        for group in groups:
            toAdd = []
            for i in group:
                toAdd.append(strs[i])
            ret.append(toAdd)

        return ret
