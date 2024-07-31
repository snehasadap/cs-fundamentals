'''
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

'''


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        zero_loss = set()
        one_loss = set()
        more_losses = set()
        
        for winner, loser in matches:
            # Add winner
            if (winner not in one_loss) and (winner not in more_losses):
                zero_loss.add(winner)
            # Add or move loser.
            if loser in zero_loss:
                zero_loss.remove(loser)
                one_loss.add(loser)
            elif loser in one_loss:
                one_loss.remove(loser)
                more_losses.add(loser)
            elif loser in more_losses:
                continue
            else:
                one_loss.add(loser)          
            
        return [sorted(list(zero_loss)), sorted(list(one_loss))]
        
