

function InfixToPostfix( str )
	stack = {}
	postfix = ""
	for i in string.gmatch(str, "%S+") do
		if (tonumber(i) ~= nil) then
			postfix = postfix .. " " .. i
		else
			if(i == "*" or i == "/") then
				if(stack[#stack] == "+" or stack[#stack] == "-" or #stack == 0) then
					table.insert(stack, i)
				else
					postfix = postfix .. " " .. stack[#stack]
					table.remove(stack)
					table.insert(stack, i)
				end
			else
				if(#stack == 0) then
					table.insert(stack, i)
				elseif(stack[#stack] == "+" or stack[#stack] == "-") then
					postfix = postfix .. " " .. stack[#stack]
					table.remove(stack)
					table.insert(stack, i)
				else
					postfix = postfix .. " " .. stack[#stack]
					table.remove(stack)
					


				end
			end
		end
	end
	while(#stack ~= 0) do
		postfix = postfix .. " " .. stack[#stack]
	end
	return postfix
end
