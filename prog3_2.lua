

function InfixToPostfix( str )
	stack = {}
	postfix = ""
	for i in string.gmatch(str, "%S+") do
		if (tonumber(i) ~= nil) then
			postfix = postfix .. " " .. i
		else
			if(i == "*" or i == "/") then
				if(stack[#stack] == "+" or stack[#stack] == "-") then
					table.insert(stack, i)
				else
					postfix = postfix .. " " .. stack[#stack]
					table.remove(stack)
					table.insert(stack, i)
				end
			else
				if(stack[#stack] == "+" or stack[#stack] == "-") then
					postfix = postfix .. " " .. stack[#stack]
					table.remove(stack)
					table.insert(stack, i)
				end
			end
		end
	while(#stack ~= 0) do
		postfix = postfix .. " " .. stack[#stack]
		end
	end
	return postfix
end
