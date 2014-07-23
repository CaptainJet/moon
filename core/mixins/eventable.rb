module Moon
  module Eventable

    ## TODO* automagically!
    #def initialize
    #  init_eventable
    #end

    def init_eventable
      @event_listeners = {:any => []}
    end

    ###
    # Adds a new event listener.
    # @param [Symbol] types The types to listen for..
    # @param [Proc] block The block we want to execute when we catch the type.
    ###
    def on(*types, &block)
      types.each do |type|
        (@event_listeners[type] ||= []).push block
      end
    end

    ###
    # @param [Event] event
    ###
    def trigger(event)
      @event_listeners[:any].each {|block| block.call(event, self) }

      return unless @event_listeners.key?(event.type)

      @event_listeners[event.type].each do |block|
        block.call(event, self)
      end
    end

  end
end
