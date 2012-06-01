-- creature.lua

function creature_getstat(_cre, _n)
  if _cre.type ~= "creature" then
    error("expected a creature object (1)")
  end
  if _n == nil then
    error("expected a stat number (2)")
  end

  local _f = pushcfunction("0x473162") --CDerivedStats::GetStat(idx)
  local _cds = createobject(_cre:getaddress("0xb0a"), "stats")
  p(_cds:stdcall(_f, _n))
end

function creature_listtriggers(_cre)
  if _cre.type ~= "creature" then
    error("expected a creature object (1)")
  end

  p("--Triggers")
  local _list = _cre:getlist("0x272")
  if (_list ~= nil) then
    local _index, _value = nil, nil
    repeat
      _index, _value = next(_list, _index)
      local _trigger
      if (_value ~= nil) then
        _trigger = createobject(_value, "trigger")
        _trigger:print()
      end
    until _index == nil
  end
end

function creature_listactions(_cre)
  if _cre.type ~= "creature" then
    error("expected a creature object (1)")
  end

  p("--Actions")
  local _action_c = createobject(_cre:getaddress("0x2be"), "action")
  p("* " .. _action_c:print(0) ..
    " [for " .. tostring(_cre:getword("0x2bc")) .. " ticks]")

  local _list = _cre:getlist("0x256")
  if (_list ~= nil) then
    local _index, _value = nil, nil
    repeat
      _index, _value = next(_list, _index)
      local _action_l
      if (_value ~= nil) then
        _action_l = createobject(_value, "action")
        _action_l:print()
      end
    until _index == nil
  end
end

function creature_listtriggerobjects(_cre)
  if _cre.type ~= "creature" then
    error("expected a creature object (1)")
  end

  p("--Objects")
  local _object = createobject(_cre:getaddress("0x42"), "object")
  if (_object:print(0) ~= "") then
    p("last AttackedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x5a"), "object")
  if (_object:print(0) ~= "") then
    p("last CommandedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x6e"), "object")
  if (_object:print(0) ~= "") then
    p("last ProtectedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x82"), "object")
  if (_object:print(0) ~= "") then
    p("last ProtectorOf: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x96"), "object")
  if (_object:print(0) ~= "") then
    p("last TargetedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0xaa"), "object")
  if (_object:print(0) ~= "") then
    p("last HitBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0xbe"), "object")
  if (_object:print(0) ~= "") then
    p("last Help shouter: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0xd2"), "object")
  if (_object:print(0) ~= "") then
    p("last Trigger: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0xe6"), "object")
  if (_object:print(0) ~= "") then
    p("last SeenBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0xfa"), "object")
  if (_object:print(0) ~= "") then
    p("last TalkedToBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x10e"), "object")
  if (_object:print(0) ~= "") then
    p("last HeardBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x122"), "object")
  if (_object:print(0) ~= "") then
    p("last SummonerOf: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x136"), "object")
  if (_object:print(0) ~= "") then
    p("last 136: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x14a"), "object")
  if (_object:print(0) ~= "") then
    p("last 14a: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x15e"), "object")
  if (_object:print(0) ~= "") then
    p("last 15e: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x172"), "object")
  if (_object:print(0) ~= "") then
    p("last 172: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x186"), "object")
  if (_object:print(0) ~= "") then
    p("last 186: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x19a"), "object")
  if (_object:print(0) ~= "") then
    p("last 19a: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x1ae"), "object")
  if (_object:print(0) ~= "") then
    p("last 1ae: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x1c2"), "object")
  if (_object:print(0) ~= "") then
    p("last 1c2: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x1d6"), "object")
  if (_object:print(0) ~= "") then
    p("last 1d6: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x1ea"), "object")
  if (_object:print(0) ~= "") then
    p("last 1ea: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x1fe"), "object")
  if (_object:print(0) ~= "") then
    p("last 1fe: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x212"), "object")
  if (_object:print(0) ~= "") then
    p("last 212: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress("0x226"), "object")
  if (_object:print(0) ~= "") then
    p("last 226: " .. _object:print(0))
  end
end

function creature_listscripts(_cre)
  if _cre.type ~= "creature" then
    error("expected a creature object (1)")
  end

  p("--Scripts")
  local _script, _name
  if u2n(_cre:getpointer("0x23a")) ~= 0 then
    _script = createobject(_cre:getpointer("0x23a"), "script")
    _name = _script:getstring(0, 8)
    p("Override (0): " .. _name)
  end
  if u2n(_cre:getpointer("0x23e")) ~= 0 then
    _script = createobject(_cre:getpointer("0x23e"), "script")
    _name = _script:getstring(0, 8)
    p("(1): " .. _name)
  end
  if u2n(_cre:getpointer("0x242")) ~= 0 then
    _script = createobject(_cre:getpointer("0x242"), "script")
    _name = _script:getstring(0, 8)
    p("Area (2): " .. _name)
  end
  if u2n(_cre:getpointer("0x246")) ~= 0 then
    _script = createobject(_cre:getpointer("0x246"), "script")
    _name = _script:getstring(0, 8)
    p("Class (3): " .. _name)
  end
  if u2n(_cre:getpointer("0x24a")) ~= 0 then
    _script = createobject(_cre:getpointer("0x24a"), "script")
    _name = _script:getstring(0, 8)
    p("Race (4): " .. _name)
  end
  if u2n(_cre:getpointer("0x24e")) ~= 0 then
    _script = createobject(_cre:getpointer("0x24e"), "script")
    _name = _script:getstring(0, 8)
    p("General (5): " .. _name)
  end
  if u2n(_cre:getpointer("0x252")) ~= 0 then
    _script = createobject(_cre:getpointer("0x252"), "script")
    _name = _script:getstring(0, 8)
    p("Default (6): " .. _name)
  end

  p("Current script: Index " .. tostring(_cre:getword("0x2b6"))
    .. " block #" .. tostring(_cre:getword("0x2b4"))
    .. " response #" .. tostring(_cre:getword("0x2b2")))
end