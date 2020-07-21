$debug

--globals
chitin = GetBaldurChitin()
game = chitin:GetObjectGame()
timer = game:GetWorldTimer()
options = game:GetOptions()

function p(text)
  CLUAConsole:DisplayText(tostring(text))
end

settagmethod(tag(0), "pow", pow)

--dump functions
dofile("tobex_ini/lua/dump.lua")
dofile("tobex_ini/lua/area.lua")
dofile("tobex_ini/lua/sprite.lua")
dofile("tobex_ini/lua/creature.lua")

dofile("tobex_ini/lua/user.lua")
