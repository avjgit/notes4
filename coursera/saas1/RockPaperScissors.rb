class RockPaperScissors

  # Exceptions this class can raise:
  class NoSuchStrategyError < StandardError
  end

 def self.winner(player1, player2)
    strategy = player1[1] + player2[1]
    strategy.upcase!
    if strategy =~ /[^RPS]/
      raise(NoSuchStrategyError, "Strategy must be one of R,P,S")
    end
    player1_lose = ['PS', 'SR', 'RP'].include? strategy
    player2_lose = ['SP', 'RS', 'PR'].include? strategy

    if (player1[1] == player2[1] or player2_lose)
        return player1
    elsif player1_lose
        return player2
    end
  end

   def self.tournament_winner(tournament)
    if tournament[0][0].kind_of?(String)
        return winner(tournament[0], tournament[1])
    else
        t1 = tournament_winner(tournament[0])
        t2 = tournament_winner(tournament[1])
        tournament_winner([t1, t2])
    end
  end

end