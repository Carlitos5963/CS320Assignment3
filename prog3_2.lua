local stack = {}
postfix = ""


function InfixToPostfix(str)
	for i in string.match(str, " ") do
		if tonumber(i) ~= nil then
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
	
	
