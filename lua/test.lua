local reponses = {"It is certain.", "It is decidedly so.", "Without a doubt.", "Yes, defubutely.",
                  "You may rely on it.", "As I see it, yes.", "Mostly likely.", "Outlook good.", "Yes.",
                  "Signs point to yes.", "Reply hazy, try again.", "Ask again later.", "Better not tell tou now.",
                  "Cannot predict now.", "Concentrate and ask again.", "Don't count on it.", "My reply is no.",
                  "Outlook not so good.", "Very doubtful."}

local function magic_ball()
    math.randomseed(os.time())
    local randomIndex = math.random(1, #reponses)
    return reponses[randomIndex]
end

while true do
    print("[Type: 'q' to Quit]You: ")
    local user = io.read()
    if user == "q" then
        print("Exiting . . .")
        break
    end
    print("Respond: " .. magic_ball())
end
