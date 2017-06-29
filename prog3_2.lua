

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
	if next(stack) ~= nil then
		postfix = postfix .. " " .. next(stack)
		end
	end
	return postfix
end

