

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
					postfix = postfix .. " " .. i
					table.remove(stack, stack[#stack])
				end
			else
				if(stack[#stack] == "+" or stack[#stack] == "-") then
					postfix = postfix .. " " .. i
					table.remove(stack, i)
				end
			end
		end
	if #stack ~= 0 then
		for i in stack	
		postfix = postfix .. " " .. stack[i]
		end
	end
	return postfix
end
