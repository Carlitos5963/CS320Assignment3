local function InfixToPostfix( str )

	stack = {}
	postfix = ""

	for i in string.gmatch(str, "%S+") do
		if (tonumber(i) ~= nil) then
			postfix = postfix .. i
		else
			if(i == "*" || i == "/") then
				if(stack[#stack] == "+" || stack[#stack] == "-") then
					table.insert(stack, i)
				else
					postfix = postfix .. i
					table.remove(stack, i)
				end
			else
				if(stack[#stack] == "+" || stack[#stack] == "-") then
					postfix = postfix .. i
					table.remove(stack, i)
				end
			end
		end
	end
	
return postfix
end
