type t('options) = Js.t({..}) as 'options;

[@bs.module] external commander : t('options) = "";

[@bs.send.pipe : t('options)] external version : string => t('options) = "version";

[@bs.send.pipe : t('options)] external option : (string, string, string => 'output) => t('options) = "option";

[@bs.send.pipe : t('options)] external parse : array(string) => 'options = "parse";

let make = () => commander;
