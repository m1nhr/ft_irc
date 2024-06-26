#ifndef	MACRO_HPP
#define MACRO_HPP

# define MAX_CLIENT_NB 10
# define SUCCESS 0
# define FAILURE -1
# define BREAK 2
# define CONTINUE 3


# define user_id(nickname, username) (":" + nickname + "!" + username + "@localhost")

/*		MESSAGE		*/
//welcome
# define RPL_WELCOME(client, IPadd) (":localhost 001 " + client + " :!!! WELCOME TO THE INTERNET RELAY NETWORK !!! | " + client +":"+ IPadd + "\r\n")
# define RPL_YOURHOST(client, serv_name) (":localhost 002 " + client + " :-Your host is " + serv_name + " (localhost), running version 1.0.1 \r\n")
# define RPL_CREATED(client, datetime) ("\n:localhost 003 " + client + " :-This server was created " + datetime + "\r\n")
# define RPL_MYINFO(client, serv_name) (":localhost 004 " + client + " :-" + serv_name + " 1.0.1 io kost k\r\n")
# define RPL_ISUPPORT(client) ("\n:localhost 005 " + client+ " :-CHANNELLEN=32 NICKLEN=9 TOPICLEN=307 : are supported by this server\r\n")


//pass
# define ERR_ALREADYREGISTERED(client) (":localhost 462 " + client + " :You may not reregister.\r\n")
# define ERR_PASSWDMISMATCH(client) (":localhost 464 " + client + " :Password incorrect.\r\n")

//privmsg
# define ERR_NOSUCHNICK(nick, target) (":localhost 401 " + nick + " " + target + " :Nickname does not exist.\r\n")
# define ERR_NOSUCHCHANNEL(chan_name) (":localhost 403 " + chan_name + " :No such channel\r\n")
# define RPL_PRIVMSG(nick, username, target, message) (":" + nick + "!" + username + "@localhost PRIVMSG " + target + " " + message + "\r\n")

//nick
# define ERR_NONICKNAMEGIVEN(client) (":localhost 431 " + client + " :There is no nickname.\r\n")
# define ERR_ERRONEUSNICKNAME(client, nickname) (":localhost 432 " + client + " " + nickname + " :Erroneus nickname\r\n")
# define ERR_NICKNAMEINUSE(client, nickname) (":localhost 433 " + client + " " + nickname + " :Nickname is already in use.\r\n")
# define RPL_NICK(oclient, uclient, client) (":" + oclient + "!" + uclient + "@localhost NICK " +  client + "\r\n")

# define ERR_NEEDMOREPARAMS(client, command) (":localhost 461 " + client + " " + command + " :Not enough parameters.\r\n")
// join
# define RPL_JOIN(user_id, channel) (user_id + " JOIN :" +  channel + "\r\n")
# define ERR_BANNEDFROMCHAN(client, channel) ("474 " + client + " " + channel + " :Cannot join channel (+b)\r\n")
# define ERR_BADCHANNELKEY(client, channel) ("475 " + client + " " + channel + " :Cannot join channel (+k)\r\n")
# define ERR_CHANNELISFULL(client, channel) ("471 " + client + " " + channel + " :Cannot join channel (+l)\r\n")

// names
# define RPL_NAMREPLY(client, channel, list_of_nicks) (":localhost 353 " + client + " " + channel + " :" + list_of_nicks + "\r\n")
# define RPL_ENDOFNAMES(client, channel) (":localhost 366 " + client + " " + channel + " :End of /NAMES list.\r\n")

// kick
# define ERR_USERNOTINCHANNEL(client, nickname, channel) ("441 " + client + " " + nickname + " " + channel + " :They aren't on that channel\r\n")
// # define ERR_CHANOPRIVSNEEDED(client, channel) ("482 " + client + " #" +  channel + " :You're not channel operator\r\n")
# define RPL_KICK(nickname, username, channel, kicked, reason) (":" + nickname + "!" + username + "@localhost" + " KICK " + channel + " " + kicked + " " + reason + "\r\n")

// topic
# define RPL_TOPIC(client, channel, topic) (":localhost 332 " + client + " " + channel + " :" + topic + "\r\n")
# define RPL_NOTOPIC(client, channel) (":localhost 331 " + client + " " + channel + " :No topic is set\r\n")
//# define ERR_NOSUCHCHANNEL(client, channel) (":localhost 403 " + client + " " + channel + " :No such channel\r\n")
# define ERR_NOTONCHANNEL(client, channel) (":localhost 442 " + client + " " + channel + " :The user is not on this channel.\r\n")

// mode
#define ERR_CHANOPRIVSNEEDED(client, channel) (":localhost 482 " + client + " " + channel + " :You're not channel operator\r\n")
#define ERR_UNKNOWNMODE(character) (":localhost 472 " + character + " :is unknown mode char to me.\r\n")

// pong
# define RPL_PONG(client, token) ("PONG reply to " + client + " " + token + "\r\n")

// part
# define RPL_PART(nickname, username, channel, reason) (":" + nickname + "!" + username + "@localhost PART " + channel + " " + (reason.empty() ? "." : reason ) + "\r\n")

// quit (":" + nickname + "!" + username + "@localhost")
# define RPL_QUIT(user_id, reason) (user_id + " QUIT :Quit: " + reason + "\r\n")
# define RPL_ERROR(user_id, reason) (user_id + " ERROR :" + reason + "\r\n")

///utils
# define ERR_FULL_SERV "[Server] You cannot join, the server is already full"
# define ERR_UNKNOWNCOMMAND(client, command) (":localhost 421 " + client + " " + command + " :Unknown command\r\n")

//mode
//# define MODE_USERMSG(channel, client, mode) ":" + channel + " MODE " + client + " :" + mode + "\r\n"
# define MODE_USERMSG(client, mode) (":" + client + " MODE " + client + " :" + mode + "\r\n")
# define MODE_CHANNELMSG(channel, mode) (":localhost MODE #" + channel + " " + mode + "\r\n")
# define MODE_CHANNELMSGWITHPARAM(channel, mode, param) (":localhost MODE #" + channel + " " + mode + " " + param + "\r\n")

# define ERR_INVITEONLYCHAN(channel) ":localhost 473 " + channel + " :" + channel + "\r\n"
# define RPL_INVITING(channel, nickname) channel + " " + nickname + "\r\n"
#endif